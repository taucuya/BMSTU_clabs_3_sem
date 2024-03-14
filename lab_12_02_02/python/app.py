import arr as arrlib

while True:
    print(
        "type 'exit' to exit\n"
        "type 'fib' to get first n fibonacci numbers\n"
        "type 'first_entry' to get indices of first entries of a number in an array\n"
    )
    inp = input("Choice: ")
    if inp == 'exit':
        break
    elif inp == 'fib':
        n = int(input("Input your n: "))
        if n <= 0:
            print("n should be positive")
            continue
        else:
            print(arrlib.fib(n))
    elif inp == 'first_entry':
        inp = input("Enter your array split by spaces: ")
        arr = list(map(int, inp.split()))
        print("Array with precise memory allocation: ")
        print(arrlib.first_entry_dcall(arr))
        print("Array with pre-allocation of memory: ")
        print(arrlib.first_entry_prealloc(arr))
    else:
        continue
exit(0)