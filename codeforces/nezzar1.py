
t=int(input())
# print("test cases",t)
for i in range(t):
    n=input();
    # print("elements in array",n)
    arr=list(map(int,input().split()))
    # print(arr)
    dict={}
    for item in arr:
        if item in dict:
            dict[item]=dict[item]+1
        else:
            dict[item]=1
    print(max(dict.values()))
