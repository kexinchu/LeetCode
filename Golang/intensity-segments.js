class IntensitySegments {
    constructor() {
        this.segments = new Map();
        this.segments.set(Number.MIN_SAFE_INTEGER, 0); // Represents -Infinity
    }

    /**
     * Adds an intensity value to the range [from, to).
     * @param {number} from - The start of the range (inclusive).
     * @param {number} to - The end of the range (exclusive).
     * @param {number} amount - The amount to add to the intensity.
     */
    add(from, to, amount) {
        this.update(from, to, (currentValue) => currentValue + amount);
    }

    /**
     * Sets an intensity value for the range [from, to).
     * @param {number} from - The start of the range (inclusive).
     * @param {number} to - The end of the range (exclusive).
     * @param {number} amount - The amount to set as the intensity.
     */
    set(from, to, amount) {
        this.update(from, to, () => amount);
    }

    /**
     * Updates the intensity value for the range [from, to) using the provided update function.
     * @param {number} from - The start of the range (inclusive).
     * @param {number} to - The end of the range (exclusive).
     * @param {function} updateFunc - A function that takes the current value and returns the updated value.
     */
    update(from, to, updateFunc) {
        const keys = Array.from(this.segments.keys());
        keys.push(from, to);
        keys.sort((a, b) => a - b);

        const updates = new Map();
        let currentValue = 0;
        for (let key of keys) {
            if (this.segments.has(key)) {
                currentValue = this.segments.get(key);
            }
            if (key >= from && key < to) {
                updates.set(key, updateFunc(currentValue));
            } else {
                updates.set(key, currentValue);
            }
        }

        for (let [key, value] of updates) {
            this.segments.set(key, value);
        }
    }

    /**
     * Returns a string representation of the current segments.
     * The output format is a list of segment start points and their corresponding intensity values.
     * @returns {string} A string representing the segments.
     */
    toString() {
        const keys = Array.from(this.segments.keys());
        keys.sort((a, b) => a - b);

        let result = [];
        let prevValue = 0;
        for (let key of keys) {
            if (key === Number.MIN_SAFE_INTEGER) continue;
            const value = this.segments.get(key);
            if (value !== prevValue) {
                result.push([key, value]);
                prevValue = value;
            }
        }

        return JSON.stringify(result);
    }
}

// Example usage:
const segments = new IntensitySegments();
console.log(segments.toString()); // "[]"

segments.add(10, 30, 1);
console.log(segments.toString()); // "[[10,1],[30,0]]"

segments.add(20, 40, 1);
console.log(segments.toString()); // "[[10,1],[20,2],[30,1],[40,0]]"

segments.add(10, 40, -2);
console.log(segments.toString()); // "[[10,-1],[20,0],[30,-1],[40,0]]"

const segmentsN = new IntensitySegments();
console.log(segmentsN.toString()); // "[]"

segmentsN.add(10, 30, 1);
console.log(segmentsN.toString()); // "[[10,1],[30,0]]"

segmentsN.add(20, 40, 1);
console.log(segmentsN.toString()); // "[[10,1],[20,2],[30,1],[40,0]]"

segmentsN.add(10, 40, -1);
console.log(segmentsN.toString()); // "[[20,1],[30,0]]"

segmentsN.add(10, 40, -1);
console.log(segmentsN.toString()); // "[[10,-1],[20,0],[30,-1],[40,0]]"
