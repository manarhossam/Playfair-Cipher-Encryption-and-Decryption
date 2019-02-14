#include<bits/stdc++.h>
using namespace std;

char grid[5][5];
char keyword[26];
char msg[100];
int mark[130]={0},len,r,c;

void createGrid();
void showGrid();
void encipher();
void decipher();
void initialize();

void menu()
{
    int n;
    cout<<"PRESS 1 : Encipher"<<endl;
    cout<<"PRESS 2 : Decipher"<<endl;
    cout<<"PRESS 3 : See Grid"<<endl;
    cout<<"PRESS 4 : Exit"<<endl;
    cout<<"Enter choice : "<<endl;
    cin>>n;
    if(n==1)
    {
        encipher();
    }
    else if(n==2)
    {
        decipher();
    }
    else if(n==4)
    {
        exit(1);
    }
    else if(n==3)
    {
        createGrid();
        showGrid();
    }
}
void initialize()
{
    memset(mark,0,sizeof(mark));
    system("CLS");
}
int main()
{
    menu();
    return 0;
}
void decipher()
{
    initialize();
    createGrid();
    cout<<"Cipher text: ";
    char cypText[150];
    cin>>cypText;
    getchar();
    int l=strlen(cypText);

    cout<<"Decipher text: ";

    int P,Q,R,S,f1,f2;
    char x,y;
    for(int i=0;i<l;i+=2)
    {
        x=cypText[i];
        y=cypText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==grid[j][k])
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==grid[j][k])
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2)
                {
                    break;
                }
            }
             if(f1 && f2)
             {
                 break;
             }
        }
        if(P==R) //same row
        {
            if(Q==0)
            {
                cout<<grid[P][4];
            }
            else
            {
                cout<<grid[P][Q-1];
            }
            if(S==0)
            {
                cout<<grid[R][4];
            }
            else
            {
                cout<<grid[R][S-1];
            }
        }
        else if(Q==S ) // same column
        {
            if(P==0)
            {
                cout<<grid[4][Q];
            }
            else
            {
                cout<<grid[P-1][Q];
            }
            if(R==0)
            {
                cout<<grid[4][S];
            }
            else
            {
                cout<<grid[R-1][S];
            }
        }
        else //opposite corner
        {
            cout<<grid[P][S]<<grid[R][Q];
        }
    }
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}

void encipher()
{
    initialize();
    createGrid();
    cout<<"Message to cipher: ";
    gets(msg);
    int l=strlen(msg);
    char reqText[150];
    int in=0,j=0;
    for(int i=0;i<l;i++)
    {
        j=i+1;
        if(msg[i]==' ')
        {
            i++;
            j++;
        }
        if(msg[j]==' ')
        {
            j++;
        }
        if(toupper(msg[i])=='J')
        {
            msg[i]='i';
        }
        if(toupper(msg[i])==toupper(msg[j]))
        {
            reqText[in]=toupper(msg[i]);
            reqText[in+1]='X';
            in++;
        }
        else
        {
            reqText[in]=toupper(msg[i]);
        }
        in++;
    }
    if(in%2!=0)
    {
        reqText[in]='X';
    }

    cout<<"Cipher text: ";

    int P,Q,R,S,f1,f2;
    char x,y;
    for(int i=0;i<in;i+=2)
    {
        x=reqText[i];
        y=reqText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==grid[j][k])
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==grid[j][k])
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2)
                {
                    break;
                }
            }
             if(f1 && f2)
             {
                 break;
             }
        }
        if(P==R)  //same row
        {
            if(Q==4)
            {
                cout<<grid[P][0];
            }
            else
            {
                cout<<grid[P][Q+1];
            }
            if(S==4)
            {
                cout<<grid[R][0];
            }
            else
            {
                cout<<grid[R][S+1];
            }
        }
        else if(Q==S ) // same column
        {
            if(P==4)
            {
                cout<<grid[0][Q];
            }
            else
            {
                cout<<grid[P+1][Q];
            }
            if(R==4)
            {
                cout<<grid[0][S];
            }
            else
            {
                cout<<grid[R+1][S];
            }
        }
        else //opposite corner
        {
            cout<<grid[P][S]<<grid[R][Q];
        }
    }
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}

void createGrid()
{
    cout<<"Keyword: ";
    cin>>keyword;
    getchar();
    len=strlen(keyword);
    mark['J']=1;
    r=0,c=0;

    for(int i=0;i<len;i++)
    {
        if(!mark[toupper(keyword[i])])
        {
            mark[toupper(keyword[i])]=1;
            grid[r][c++]=toupper(keyword[i]);
            if(c%5==0)
            {
                c=0;
                r++;
            }
        }
    }
    for(int i='A';i<='Z';i++)
    {
        if(mark[i]==0)
        {
            grid[r][c++]=i;
            mark[i]=1;
            if(c%5==0)
            {
                if(r==4 && c==5)
                {
                    break;
                }
                r++;
                c=0;
            }
        }
    }
}

void showGrid()
{
   cout<<"5x5 Matrix"<<endl;
   for(int i=0;i<5;i++)
   {
       for(int j=0;j<5;j++)
       {
           cout<<grid[i][j]<<" ";
       }
       cout<<endl;
   }
}
