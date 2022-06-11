class Solution:
    def fib(self, n: int) -> int:
        f=[];
        f.append(0);
        f.append(1);
        for i in range(2,n+1):
            f.append(f[i-1]+f[i-2])
        return f[n]