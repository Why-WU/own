
#include <stdio.h> 
# define N 100  //如果要录入X个字节则 N=X  
int Getchar(char A[],int min,int max);//直到用户输入的字符串长度在[min,max]之间时 函数结束 返回字符串A的长度  
int BF(char a[],char b[],int c[]);//a为主串 b为次串 c[]存储匹配的下标 函数返回 匹配的个数 
int main(){  
    char A[N+1],B[N+1]; 
    int C[N],L,num,i; 
    do{
    printf("请输入主字符串A[%d,%d]:",1,N);
    L=Getchar(A,1,N);
    printf("请输入次字符串B[%d,%d]:",1,L);
    Getchar(B,1,L);
    num=BF(A,B,C);
    printf("B在A中共%d个,下标:",num);
    for(i=0;i<num;i++)
    printf("%d ",C[i]);
    printf("\n");
    }while(1);
    return 0;  
}  
int BF(char a[],char b[],int c[])//a为主串 b为次串 c[]存储匹配的下标 函数返回 匹配的个数 
{                       
    int i=0,j=0,k=0;   
    do{  
        if (b[j]&&a[i++]==b[j])++j;  
        else  
        {  
            b[j]?(i-=j):(c[k++]=i-j);   
            j=0;              
        }  
    }while(a[i-1]);  
      return k;  
}  
int Getchar(char *A,int min,int max)//长度在[min,max]  <闭区间>  之间时 函数结束 返回字符串A的长度      
{      
    int B,C;    
 do{      
        A[max]=B=C=0;  
        while((A[B++]=getchar())!='\n'&&B<max);  
        if(A[B-1]!='\n')while(getchar()!='\n'&&++C);      
        else A[--B]=0;   
    if(C||B&&B<min)  
       printf("您录入的字符串长度:%d字节\n只录入(%d--%d)个字节!\n",B+C,min,max);      
    }while(C||B<min);      
    return B;    
}
--------------------- 
作者：zhagoodwell 
来源：CSDN 
原文：https://blog.csdn.net/zhagoodwell/article/details/77422530 
版权声明：本文为博主原创文章，转载请附上博文链接！