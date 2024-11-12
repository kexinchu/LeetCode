package main

import (
	"fmt"
	"sort"
)

// IntensitySegments represents a structure to manage intensity by segments.
// The segments map stores intensity values at specific points.
type IntensitySegments struct {
	segments map[int]int
}

// NewIntensitySegments creates a new instance of IntensitySegments with
// an initial segment value of 0 from -Infinity.
func NewIntensitySegments() *IntensitySegments {
	segments := make(map[int]int)
	segments[-1<<63] = 0 // Represents -Infinity
	return &IntensitySegments{segments: segments}
}

// Add increases the intensity for a given range [from, to) by the specified amount.
func (is *IntensitySegments) Add(from, to, amount int) {
	is.update(from, to, func(currentValue int) int { return currentValue + amount })
}

// Set sets the intensity for a given range [from, to) to the specified amount.
func (is *IntensitySegments) Set(from, to, amount int) {
	is.update(from, to, func(currentValue int) int { return amount })
}

// update modifies the segments between the given range [from, to)
// using the provided update function.
func (is *IntensitySegments) update(from, to int, updateFunc func(int) int) {
	keys := make([]int, 0, len(is.segments)+2)
	for key := range is.segments {
		keys = append(keys, key)
	}
	keys = append(keys, from, to)
	sort.Ints(keys)

	updates := make(map[int]int)
	currentValue := 0
	for _, key := range keys {
		if value, exists := is.segments[key]; exists {
			currentValue = value
		}
		if key >= from && key < to {
			updates[key] = updateFunc(currentValue)
		} else {
			updates[key] = currentValue
		}
	}

	for key, value := range updates {
		is.segments[key] = value
	}
}

// ToString returns a string representation of the current segments.
// The format represents changes in intensity values at specific points.
func (is *IntensitySegments) ToString() string {
	keys := make([]int, 0, len(is.segments))
	for key := range is.segments {
		keys = append(keys, key)
	}
	sort.Ints(keys)

	result := []string{}
	prevValue := 0
	for _, key := range keys {
		if key == -1<<63 {
			continue
		}
		value := is.segments[key]
		if value != prevValue {
			result = append(result, fmt.Sprintf("[%d,%d]", key, value))
			prevValue = value
		}
	}

	return fmt.Sprintf("[%s]", stringJoin(result, ","))
}

// stringJoin joins the elements of a string slice with a specified separator.
func stringJoin(elements []string, sep string) string {
	if len(elements) == 0 {
		return ""
	}
	joined := elements[0]
	for i := 1; i < len(elements); i++ {
		joined += sep + elements[i]
	}
	return joined
}

// Example usage
func TestSegments() {
	segments := NewIntensitySegments()
	fmt.Println(segments.ToString()) // "[]"

	segments.Add(10, 30, 1)
	fmt.Println(segments.ToString()) // "[[10,1],[30,0]]"

	segments.Add(20, 40, 1)
	fmt.Println(segments.ToString()) // "[[10,1],[20,2],[30,1],[40,0]]"

	segments.Add(10, 40, -2)
	fmt.Println(segments.ToString()) // "[[10,-1],[20,0],[30,-1],[40,0]]"

	segmentsN := NewIntensitySegments()
	fmt.Println(segmentsN.ToString()) // "[]"

	segmentsN.Add(10, 30, 1)
	fmt.Println(segmentsN.ToString()) // "[[10,1],[30,0]]"

	segmentsN.Add(20, 40, 1)
	fmt.Println(segmentsN.ToString()) // "[[10,1],[20,2],[30,1],[40,0]]"

	segmentsN.Add(10, 40, -1)
	fmt.Println(segmentsN.ToString()) // "[[20,1],[30,0]]"

	segmentsN.Add(10, 40, -1)
	fmt.Println(segmentsN.ToString()) // "[[10,-1],[20,0],[30,-1],[40,0]]"
}
