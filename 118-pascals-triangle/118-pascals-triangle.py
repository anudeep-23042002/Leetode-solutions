class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        arr=[];
        m=[];
        s=0;
        for i in range(1,numRows+1):
            p=[];
            if(i==1):
                p.append(1);
            elif(i==2):
                p.append(1);
                p.append(1);
            else:
                p.append(1);
                for j in range(1,ceil(i/2)):
                    p.append(m[j]+m[j-1]);
                if(i%2==0):
                    s+=1;
                
                for z in range(s,-1,-1):
                    p.append(p[z]);
            m=p;
            arr.append(m);
        return arr;