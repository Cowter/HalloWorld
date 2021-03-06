#include "iostream"
#include <string.h>
using namespace std;

struct Lesson{
	char name[20];
	int grade;
};

struct Student{
	char name[20];
	int id;
	Lesson lessons[10];
	int LesCount;
}students[1000];

int StuCount = 0;

void list();
void add();
void del();
void grade();
void stuinput(struct Student &student);
int stufind(int id);
int lesfind(struct Student &student,char* name);
void leslist(struct Student &student);

int main(){
	int action;
	do{
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)学生列表"<<endl;
		cout<<"2)选课"<<endl;
		cout<<"3)退选"<<endl;
		cout<<"4)录入成绩"<<endl;
		cout<<"5)退出程序"<<endl;

		cin>>action;
		switch(action){
		case 1:
			list();
			break;
		case 2:
			add();
			break;
		case 3:
			del();
			break;
		case 4:
			grade();
			break;		
		case 5:
			return 0;
		default:
			cout<<"输入错误";
		}
	}while(1);
}

void list(){
	cout<<"-------列表-------"<<endl;
	cout<<"姓名  学号"<<endl<<"  科目"<<endl<<"  成绩"<<endl;
	for(int i=0;i<StuCount;i++){
		cout<<students[i].name<<"   "<<students[i].id<<endl;
		cout<<"  ";
		for(int j=0;j<students[i].LesCount;j++){
			cout<<students[i].lessons[j].name<<"\t";
		}
		cout<<endl;
		cout<<"  ";
		
		for(int j=0;j<students[i].LesCount;j++){
			cout<<students[i].lessons[j].grade<<"\t";
		}
		cout<<endl<<endl;
	}
}

void add(){
	struct Student student;
	stuinput(student);
	int i,j;
	char name[20];
	i=stufind(student.id);
	if(i == StuCount){
		strcpy_s(students[i].name , student.name);
		students[i].id = student.id;			
		students[i].LesCount=0;
		StuCount++;
	}
	leslist(students[i]);
	cout<<"0)结束选课"<<endl;
	cout<<"输入要选择的课程名称"<<endl;
	for(j=students[i].LesCount;j<10;j++){
		cin>>name;
		char name0[20]="0";
		if(strcmp(name,name0)!=0){
			strcpy_s(students[i].lessons[j].name,name);
		}
		else{
			break;
		}
	}
	students[i].LesCount=j;
}

void del(){
	struct Student student;
	stuinput(student);
	int i,j;
	i=stufind(student.id);
	if(i == StuCount){
		cout<<"姓名或学号错误"<<endl;
	}
	else{
		cout<<students[i].LesCount;
		for(int k=students[i].LesCount;k>0;k--){
			leslist(students[i]);
			cout<<"0)结束退选"<<endl;
			cout<<"输入选项编号："<<endl;
			cin>>j;
			if(j&&j<=students[i].LesCount){
				strcpy_s(students[i].lessons[j-1].name,students[i].lessons[students[i].LesCount-1].name);
				students[i].lessons[j-1].grade=students[i].lessons[students[i].LesCount-1].grade;
				students[i].LesCount--;
			}
			else if(j){
				cout<<"输入错误";
			}
			else{
				break;
			}
		}
	}
}

void grade(){
	int id,i;
	do{
		cout<<"起始学号：";
		cin>>id;
		i=stufind(id);
		if(i==StuCount){
			cout<<"学号错误"<<endl;
		}
		else{
			break;
		}
	}while(1);
	for(;i<StuCount;i++){
		cout<<students[i].name<<"\t"<<students[i].id<<endl;
		for(int j=0;j<students[i].LesCount;j++){
			cout<<students[i].lessons[j].name<<":\t";
			cin>>students[i].lessons[j].grade;
		}
		cout<<"是否继续输入？（y/n）"<<endl;
		char acton;
		cin>>acton;
		if (acton=='y'){
			continue;
		}
		else if (acton=='n'){
			cout<<"输入中止"<<endl;
			break;
		}
		else{
			cout<<"选项错误，继续输入"<<endl;
		}
	}
	cout<<"输入完成"<<endl;
}

void stuinput(struct Student &student){
	cout<<"姓名";
	cin>>student.name;

	cout<<"学号";
	cin>>student.id;
}

int stufind(int id){
	int i;
	for(i=0;i<StuCount;i++){
		if(id==students[i].id){
		break;
		}
	}
	return i;
}

int lesfind(struct Student &student,char* name){
	int i;
	for(i=0;i<student.LesCount;i++){
		if(strcmp(name,student.lessons[i].name)){
			break;
		}
	}
	return i;
}

void leslist(struct Student &student){
	cout<<student.name<<endl;
	cout<<"已选课程:"<<endl;
	for(int i=0;i<student.LesCount;i++){
		cout<<i+1<<")"<<student.lessons[i].name<<endl;
	}
}