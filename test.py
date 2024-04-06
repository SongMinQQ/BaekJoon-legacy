H,M = map(int,input().split())
if M - 45 < 0 : 
    print(H-1, 60-(45 - M))
else : 
    print(H, M - 45)