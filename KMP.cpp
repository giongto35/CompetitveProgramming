//build failure function
f[0]=f[1]=0;
for (int i=2;i<=m;i++){
    int j=f[i-1];
    while(true){
        if (p[j]==p[i-1]){f[i]=j+1;break;}
        if (j==0){f[i]=0;break;}
        j=f[j];
    }
}
//Knuth-Morris-Pratt
int i=0,j=0;
while(true){
    if (j==n) break;
    if (s[j]==p[i]){
        i++; j++;
        if (i==m) cout<<j-m+1<<" ";
    }
    else
        if (i>0) i=f[i];
        else j++;
}
