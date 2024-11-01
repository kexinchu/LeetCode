import sys
import requests
from bs4 import BeautifulSoup

def print_unicode_grid(url):
    # Step 1: 获取HTML内容
    response = requests.get(url)
    if response.status_code != 200:
        print("无法获取文档内容。请检查URL。")
        return
    
    # 使用BeautifulSoup解析HTML
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # 查找所有的表格行(tr)元素
    spans = soup.find_all('span', class_='c2')

    # 提取数据
    data = []
    start = False
    idx = 0
    for span in spans:
        if start:
            if idx % 3 == 0:
                data.append([span.text])
            else:
                data[idx // 3].append(span.text)
            idx += 1
        if start == False and span.text == "y-coordinate":
            start = True
    
    assert len(data) > 0
    # print(data)
    # 解析坐标和字符
    coordinates = []
    for point in data:
        if len(point) != 3:
            continue
        coordinates.append((int(point[0]), int(point[2]), point[1]))
    # print(coordinates)

    # Step 3: 找到网格大小
    max_x = max(x for x, y, char in coordinates)
    max_y = max(y for x, y, char in coordinates)

    # 创建并填充2D网格
    grid = [[" " for _ in range(max_x + 1)] for _ in range(max_y + 1)]
    
    # 将字符放入对应位置
    for x, y, char in coordinates:
        grid[max_y - y][x] = char

    # Step 4: 打印网格
    for row in grid:
        print("".join(row))

# 示例使用
if __name__ == "__main__":
    url = "https://docs.google.com/document/d/e/2PACX-1vQGUck9HIFCyezsrBSnmENk5ieJuYwpt7YHYEzeNJkIb9OSDdx-ov2nRNReKQyey-cwJOoEKUhLmN9z/pub"
    # url = "https://docs.google.com/document/d/e/2PACX-1vRMx5YQlZNa3ra8dYYxmv-QIQ3YJe8tbI3kqcuC7lQiZm-CSEznKfN_HYNSpoXcZIV3Y_O3YoUB1ecq/pub"
    print_unicode_grid(url)
