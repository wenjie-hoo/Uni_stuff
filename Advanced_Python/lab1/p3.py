def table(x1, x2, y1, y2, d):
    if d == 0:
        return
    x_range = range(int(x1), int(x2) + 1, int(d))
    y_range = range(int(y1), int(y2) + 1, int(d))
    header = "\t"
    for x in x_range:
        header += str(x) + "\t"
    print(header)
    for y in y_range:
        row = str(y) + "\t"
        for x in x_range:
            product = x * y
            row += str(product) + "\t"
        print(row)

x1 = -2.0
x2 = 5.0
y1 = 2.0
y2 = 5.0
d = 1
table(x1, x2, y1, y2, d)
