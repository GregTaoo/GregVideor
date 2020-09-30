#include<iostream>
#include<Windows.h>
#include<cstdio>
#include<fstream>
#include<commdlg.h>
#include<string>
using namespace std;
bool iscdbg=false;
string cmline; 
char cl1[MAX_PATH]={0};
char cl2[MAX_PATH]={0};
char cl3[MAX_PATH]={0};
char cl4[MAX_PATH]={0};
int readset(){
	ifstream in("set.data");
    in>>iscdbg;
    in.close();
    ifstream cmin("cmline.data");
    getline(cmin,cmline);
    for(int i=0;i<cmline.length();++i){
    	cl1[i]=cmline[i];
	}
	getline(cmin,cmline);
    for(int i=0;i<cmline.length();++i){
    	cl2[i]=cmline[i];
	}
	getline(cmin,cmline);
    for(int i=0;i<cmline.length();++i){
    	cl3[i]=cmline[i];
	}
	getline(cmin,cmline);
    for(int i=0;i<cmline.length();++i){
    	cl4[i]=cmline[i];
	}
	cmin.close();
    return 0;
}
int VideoPlayer(){
	char szBuffer[MAX_PATH] = {0}; 
	char commandPath[MAX_PATH]={0};
    OPENFILENAME ofn= {0}; 
    ofn.lStructSize = sizeof(ofn); 
    ofn.lpstrFilter = ("所有视频或音频文件(*.*)\0*.*\0");//要选择的文件后缀 
    ofn.lpstrInitialDir = ("C:\\");//默认的文件路径 
    ofn.lpstrFile = szBuffer;//存放文件的缓冲区 
    ofn.nMaxFile = sizeof(szBuffer)/sizeof(*szBuffer); 
    ofn.nFilterIndex = 0; 
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER ;//标志如果是多选要加上OFN_ALLOWMULTISELECT
    BOOL bSel = GetOpenFileName(&ofn);
    if(!szBuffer[0]){
    	return 1;
	}else{
	    printf("Path:\"%s\"",szBuffer);
	    if(iscdbg==false){
	    	sprintf(commandPath,cl1,szBuffer);
		}else{
			sprintf(commandPath,cl2,szBuffer);
		}
        system(commandPath);
        return 0;
	}
}
int StreamPlayer(){
	cout<<"Input the Domain Host:";
	char DomainHost[MAX_PATH];
	char commandPath[MAX_PATH];
	cin>>DomainHost;
	if(!(DomainHost[0]=='h'||DomainHost[0]=='r')){
		return 1;
	}else{
		printf("Path:\"%s\"",DomainHost);
		if(iscdbg==false){
			sprintf(commandPath,cl1,DomainHost);
		}else{
			sprintf(commandPath,cl2,DomainHost);
		}
        system(commandPath);
        return 0;
	}
}
int CCTVPlayer(){
	cout<<"Input the Number:";
	int DomainHost=1;
	char commandPath[MAX_PATH];
	cin>>DomainHost;
	if(!(DomainHost<=15&&DomainHost>=1)){
		return 1;
	}else{
		printf("Path:\"%d\"",DomainHost);
		if(iscdbg==false){
			sprintf(commandPath,cl3,DomainHost);
		}else{
			sprintf(commandPath,cl4,DomainHost);
		}
        system(commandPath);
        return 0;
	}
}
int Settings(){
	system("cls");
	char ipchar='a';
	ofstream out("set.data");
	cout<<"Video Player Set: \nIf yes, press 'y' and enter. If no, press 'n' and enter. The default if No\n";
	cout<<"Scanning debug information? >>:";
	cin>>ipchar;
	if(ipchar=='y'){
		out<<"1 ";
	}else{
		out<<"0 ";
	}
	out.close();
	return 0;
}
int main(){
	if(readset()!=0) return 0;
	char inputNum='0';
	int returnNum=0;
	while(true){
		readset();
		printf("Menu:\n1.VideoPlayer\n2.StreamPlayer\n3.CCTVPlayer\ns.Settings\n\nInput your task number:");
	    cin>>inputNum;
	    switch(inputNum)
	    {
	     	case '1':{
	     		returnNum=VideoPlayer();
				break;
			}
	     	case '2':{
	     		returnNum=StreamPlayer();
				break;
			}
			case '3':{
				returnNum=CCTVPlayer();
				break;
			}
	     	case 's':{
	     		returnNum=Settings();
				break;
			}
	      	default:break;
     	} 
     	if(returnNum!=0){
    		cout<<"Failed to open!\n";
    		system("pause");
    	}
    	system("cls");
	}
}
