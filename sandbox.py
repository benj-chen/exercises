
def ext_gcd(a, b):
    x = 1
    y = 0
    x1 = 0
    y1 = 1
    a1 = a
    b1 = b

    while b1 > 0:
        q = a1 // b1
        x, x1 = x1, x - q * x1
        y, y1 = y1, y - q * y1
        a1, b1 = b1, a1 - q * b1

    return x, y


if __name__ == '__main__':
    n = int(input())
    t = input().split(',')
    divs = []
    mx = [-1, -1]
    lcm = 1
    for i in range(len(t)):
        if t[i] == 'x':
            continue

        t[i] = int(t[i])

        k = i
        k %= t[i]
        k = t[i] - k
        k %= t[i]

        divs.append([int(t[i]), k])
        lcm *= int(t[i])
        if mx[0] == -1 or divs[-1][0] > mx[0]:
            mx = divs[-1]

    print(divs)

    while len(divs) > 1:
        n1, a1 = divs[-1]
        n2, a2 = divs[-2]

        divs.pop()
        divs.pop()
        m1, m2 = ext_gcd(n1, n2)
        x = a1 * m2 * n2 + a2 * m1 * n1
        x %= n1 * n2

        if x < 0:
            x += n1 * n2
        divs.append([n1 * n2, x])
        print(divs)
    print(divs[0][1])