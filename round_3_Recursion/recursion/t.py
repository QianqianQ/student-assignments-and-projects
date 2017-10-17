count = 0

def fibo(n):
    global count
    count += 1
    if n <= 1:
        return n
    else:
        return fibo(n - 1) + fibo(n - 2)

def main():
    print(fibo(7))
    print(count)

if __name__ == '__main__':
    main()