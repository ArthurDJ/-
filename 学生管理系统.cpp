#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define sstu sizeof(struct student)
#define scou sizeof(struct course)
#define sch sizeof(struct choice)

FILE *fp;
ifstream in;
ofstream out;
void CHMenu();
void StuMenu();
void CouMenu();
void readch();
void readstu();
void readcou();
void QcouMenu();
void outputch();
void outputcou();
void outputstu();
void DelcouMenu();
void DelstuMenu();
void DelcouMenu();
void savedate();
void savedate_ch();
void savedate_cou();
void addch(int n);
void addcou(int n);
void addstu(int n);
void update(int qid);
void QchMenu(int qid);
void QstuMenu(int qid);
void QcouMenu(int qid);
void QcouMenu(int qid);
void deletecou_id(int did);
void deletestu_id(int did);
void Delch(int a, int b);
void deletestu_name(char *dname);
void deletecou_name(char *dname);
 


typedef struct student{
	int id;         
	char name[20];
	char grade[20];
	char mayor[20];
	int age;
	struct student *next;         
}STU;

typedef struct course{
	int id;
	char name[20];
	char teacher[20];
	struct course *next;
}COU;

typedef struct choice{
	int cou_id;
	int stu_id;
	int mark;
	struct choice *next;
}CH;

int sum = 0;
CH *f, *e;
STU *first, *end;
COU *ffirst, *eend;

void menu(){
	system("cls"); 
	cout << "Thank you for choosing our products." << endl;
	cout << "We will serve you wholeheartedly." << endl;
	cout << "***********Main menu************" << endl;
    cout << "\t1.Student management system" << endl;
    cout << "\t2.Course selection management system" << endl;
    cout << "\t3.Student course system" << endl;
    cout << "\t0.Quit" << endl;
    cout << "********************************" << endl;
    cout << "choose one£º";
    int no;
    cin >> no;
    switch(no){
		case 0:
			cout << "Thank you for choosing our products." << endl;
			Sleep(1000);
			return;
		case 1:
			StuMenu();
			break;
		case 2:
		    CouMenu();
		    break;
		case 3:
			CHMenu();
			break;
	}
}

void CouMenu(){
	system("cls");
	cout << "***********menu************" << endl;
    cout << "\t1.Add course information" << endl;
    cout << "\t2.Delete course information" << endl;
    cout << "\t3.Query about course information" << endl;
    cout << "\t4.Output course information" << endl;
    cout << "\t5.Read course date" << endl;
    cout << "\t6.Save course date" << endl;
    cout << "\t0.Back" << endl;
    cout << "***************************" << endl;
    cout << "choose one£º";
    int no, qid;
    cin >> no;
    switch(no){
		case 0:{
			menu();
			break;
		}
		case 1:{
			int addnum;
			cout << "Output course number you want add:" << endl;
			cin >> addnum;
			addcou(addnum);
			CouMenu();
			break;
		}
		case 2:{
			DelcouMenu();
			CouMenu();
			break;
		}
		case 3:{
			cout << "Query by course id, output it." << endl;
			cin >> qid;
			QcouMenu(qid);
			CouMenu();
			break;
		}
		case 4:{
			outputcou();
			CouMenu();
			break;
		}
		case 5:{
			readcou();
			CouMenu();
			break;
		}
		case 6:{
			savedate_cou();
			CouMenu();
			break;
		}
	}
}

void StuMenu(){
	system("cls");
	cout << "***********menu************" << endl;
    cout << "\t1.Add student information" << endl;
    cout << "\t2.Delete student information" << endl;
    cout << "\t3.Query about student information" << endl;
    cout << "\t4.Output student information" << endl;
    cout << "\t5.Update student information" << endl;
    cout << "\t6.Read student date" << endl;
    cout << "\t7.Save student date" << endl;
    cout << "\t0.Back" << endl;
    cout << "***************************" << endl;
    cout << "choose one£º";
    int no, qid;
    cin >> no;
    switch(no){
		case 0:{
			menu();
			break;
		}
		case 1:{
			cout << "Output student number you want add:" << endl;
			cin >> qid;
			addstu(qid);
			StuMenu();
			break;
		}
		case 2:{
			DelstuMenu();
			StuMenu();
			break;
		}
		case 3:{
			cout << "Query by student id, output it." << endl;
			cin >> qid;
			QstuMenu(qid);
			StuMenu();
			break;
		}
		case 4:{
			outputstu();
			StuMenu();
			break;
		}
		case 5:{
			cout << "Update by student id, output it." << endl;
			cin >> qid;
			update(qid);
			StuMenu();
			break;
		}
		case 6:{
			readstu();
			StuMenu();
			break;
		}
		case 7:{
			savedate();
			StuMenu();
			break;
		}
	}
}

void CHMenu(){
	system("cls");
	cout << "***********menu************" << endl;
    cout << "\t1.Add student's course" << endl;
    cout << "\t2.Delete student's course"<< endl;
    cout << "\t3.Query student's course" << endl;
    cout << "\t4.Output student's course" << endl;
    cout << "\t5.Read student's course course date" << endl;
    cout << "\t6.Save student's course course date" << endl;
    cout << "\t0.Back" << endl;
    cout << "***************************" << endl;
    cout << "choose one£º";
    int no, qid;
    cin >> no;
    switch(no){
		case 0:{
			menu();
			break;
		}
		case 1:{
			cout << "Output student you want add:" << endl;
			cin >> qid;
			addch(qid);
			CHMenu();
			break;
		}
		case 2:{
			int id, stuid;
			cout << "Output course id" << endl;
			cin >> id;
			cout << "Output student id" << endl;
			cin >> stuid;
			Delch(id, stuid);
			CHMenu();
			break;
		}
		case 3:{
			cout << "Query by student id, output it." << endl;
			cin >> qid;
			QchMenu(qid);
			CHMenu();
			break;
		}
		case 4:{
			outputch();
			CHMenu();
			break;
		}
		case 5:{
			readch();
			CHMenu();
			break;
		}
		case 6:{
			savedate_ch();
			CHMenu();
			break;
		}
	}
}

void outputstu(){
	STU *p = first;
	cout << 1 << endl; 
	while(p->next != NULL){
		printf("id: %d\n", p->next->id);
//		cout << "id: " << p->next->id << endl;
		cout << "name: " << p->next->name << endl;
		cout << "grade: " << p->next->grade << endl;
		cout << "mayor: " << p->next->mayor << endl;
		cout << "age: " << p->next->age << endl;	
		p = p->next;
	}
	cout << 2 << endl;
	system("pause");
}

void DelstuMenu(){
	system("cls");
	cout << "Delete by student id, output 1 with id" << endl;
	cout << "Delete by student name, output 2 with name" << endl;
	int n;
	cin >> n;
	switch(n){
		case 1:{
			int del;
			cin >> del;
			deletestu_id(del);
			break;
		}
		case 2:{
			char dname[20];
			cin >> dname;
			deletestu_name(dname);
			break;
		}
	}
}

void QstuMenu(int qid){
	STU *p = first;
	while(p->next != NULL){
		if(p->next->id == qid){
			cout << "id: " << p->next->id << endl;
			cout << "name: " << p->next->name << endl;
			cout << "grade: " << p->next->grade << endl;
			cout << "mayor: " << p->next->mayor << endl;
			cout << "age: " << p->next->age << endl;
			return;
		}
		else{
			p = p->next;
		}
	}
	system("pause");
}

void readstu(){
	system("cls");
	fp = fopen("stu.txt","rb");
	STU *p1, *p2;
	first = NULL;	
	p1 = p2 = (STU *)malloc(sstu);
	int len = 0;
	
	if(NULL == fp){
		cout << "didi" << endl;
//		return;
	}
	fscanf(fp,"%d",&p1->id);
	while(p1->id != 0){
		fscanf(fp,"%s",p1->name);		
		fscanf(fp,"%s",p1->grade);
        fscanf(fp,"%s",p1->mayor);
		fscanf(fp,"%d",&p1->age);
		len++;
		if(len == 1){
			first = p1;
		}
		else{
			p2->next = p1;
		}
		p2 = p1;
		end = p2;
		p1 = (STU *)malloc(sstu);
		fscanf(fp,"%d", &p1->id);
		end->next = NULL;
	}
	cout << "Read over." << endl;
	system("pause");
	StuMenu();
}

void addstu(int n){
	system("cls");
	STU *p1;
	end->next = p1;
	p1 = (STU *)malloc(sstu);
	
	for(int i = 0; i < n; i++){
		cout << "Input student id:" << endl;
		scanf("%d", p1->id);
		cout << "Input student name:" << endl;
		scanf("%s", p1->name);
		cout << "Input student grade:" << endl;
		scanf("%s", p1->grade);
		cout << "Input student mayor:" << endl;
		scanf("%s", p1->mayor);
		cout << "Input student age:" << endl;
		scanf("%d", p1->age);
		end->next = p1;
		end = p1;
	}
}

void findstu_id(int qid){
	STU *p = first;
	while(p->next != NULL){
		if(p->next->id == qid){
			cout << "id: " << p->next->id << endl;
			cout << "name: " << p->next->name << endl;
			cout << "grade: " << p->next->grade << endl;
			cout << "mayor: " << p->next->mayor << endl;
			cout << "age: " << p->next->id << endl;
			return;
		}
		else{
			p = p->next;
		}
	}
}

void findstu_name(char *qname){
	STU *p = first;
	while(p->next != NULL){
		if(strcmp(p->next->name, qname) == 0){
			cout << "id: " << p->next->id << endl;
			cout << "name: " << p->next->name << endl;
			cout << "grade: " << p->next->grade << endl;
			cout << "mayor: " << p->next->mayor << endl;
			cout << "age: " << p->next->id << endl;
			return;
		}
		else{
			p = p->next;
		}
	}
}

void deletestu_id(int did){
	STU *p = first;
	while(p->next != NULL){
		if(p->next->id == did){
			STU *q;
			q = p->next;
			p->next = p->next->next;
			delete(q);
			return;
		}
		else{
			p = p->next;
		}
	}
}

void deletestu_name(char *dname){
	STU *p = first;
	while(p->next != NULL){
		if(strcmp(p->next->name, dname) == 0){
			STU *q;
			q = p->next;
			p->next = p->next->next;
			delete(q);
			return;
		}
		else{
			p = p->next;
		}
	}
	
}

void update(int qid){
	STU *p = first;
	while(p->next != NULL){
		if(p->next->id == qid){
			cout << "Input student name:" << endl;
			scanf("%s", p->name);
			cout << "Input student grade:" << endl;
			scanf("%s", p->grade);
			cout << "Input student mayor:" << endl;
			scanf("%s", p->mayor);
			cout << "Input student age:" << endl;
			scanf("%d", p->age);
			return;
		}
		else{
			p = p->next;
		}
	}
}

void savedate(){
	system("cls");
	STU *p = first;
	fp = fopen("stu.txt","wt");
	while(p->next != NULL){
		fprintf(fp, "%d\t", p->id);    		
        fprintf(fp, "%s\t", p->name); 			
		fprintf(fp, "%s\t", p->grade);	
        fprintf(fp, "%s\t", p->mayor);	
		fprintf(fp, "%d", p->age);
		fprintf(fp, "%c", '\n');
		p = p->next;
	}
	fprintf(fp, "0");
	fclose(fp);
	cout << "Save student information over." << endl;
	system("pause");
}

void readcou(){
	system("cls");
	fp = fopen("cou.txt","rb");
	ffirst = NULL;
	COU *p1, *p2;
	p1 = p2 = (COU *)malloc(scou);
	int len = 0;
	fscanf(fp,"%d",&p1->id); 
	while(p1->id != 0){
		fscanf(fp,"%s",p1->name);		
		fscanf(fp,"%s",p1->teacher);
		len++;
		if(len == 1){
			ffirst = p1;
		}
		else{
			p2->next = p1;
		}
		p2 = p1;
		eend = p2;
		p1 = (COU *)malloc(scou);
		fscanf(fp,"%d",&p1->id);
		eend->next = NULL;
	}
	cout << "Read over." << endl;
	system("pause");
}

void addcou(int n){
	system("cls");
	COU *p1;
	p1 = (COU *)malloc(scou);
	eend->next = p1;
	for(int i = 0; i < n; i++){
		cout << "Input source id:" << endl;
		scanf("%d", &p1->id);
		cout << "Input source name:" << endl;
		scanf("%s", p1->name);
		cout << "Input source teacher name:" << endl;
		scanf("%s", p1->teacher);
		eend->next = p1;
		eend = p1;
		eend->next = NULL; 
	}
}

void DelcouMenu(){
	system("cls");
	cout << "Delete by course id, output 1 with id" << endl;
	cout << "Delete by course name, output 2 with name" << endl;
	cout << "Want back, output 3." << endl;
	int n;
	cin >> n;
	switch(n){
		case 1:{
			int del;
			cin >> del;
			deletecou_id(del);
			break;
		}
		case 2:{
			char dname[20];
			cin >> dname;
			deletecou_name(dname);
			break;
		}
		case 3:{
			CouMenu();
			break;
		}
	}
}

void deletecou_id(int did){
	COU *p = ffirst;
	while(p->next != NULL){
		if(p->next->id == did){
			COU *q;
			q = p->next;
			p->next = p->next->next;
			delete(q);
			return;
		}
		else{
			p = p->next;
		}
	}
}

void deletecou_name(char *dname){
	COU *p = ffirst;
	while(p->next != NULL){
		if(strcmp(p->next->name, dname) == 0){
			COU *q;
			q = p->next;
			p->next = p->next->next;
			delete(q);
			return;
		}
		else{
			p = p->next;
		}
	}
	
}

void QcouMenu(int qid){
	COU *p = ffirst;
	while(p->next != NULL){
		if(p->next->id == qid){
			cout << "id: " << p->next->id << endl;
			cout << "name: " << p->next->name << endl;
			cout << "grade: " << p->next->teacher << endl;
			return;
		}
		else{
			p = p->next;	
		}
	}
}

void outputcou(){
	COU *p = ffirst;
	while(p->next != NULL){
		cout << "id: " << p->next->id << endl;
		cout << "name: " << p->next->name << endl;
		cout << "course teacher: " << p->next->teacher << endl;
		p = p->next;
	}
	system("pause");
}

void savedate_cou(){
	system("cls");
	COU *p = ffirst;
	fp = fopen("cou.txt","wt");
	while(p->next != NULL){
		fprintf(fp, "%d\t", p->id);    		
        fprintf(fp, "%s\t", p->name); 			
		fprintf(fp, "%s\t", p->teacher);
		p = p->next;
	}
	fprintf(fp,"0");
	fclose(fp);
	cout << "Save course information over." << endl;
	system("pause");
}

void addch(int n){
	system("cls");
	CH *p1;
	p1 = (CH *)malloc(sch);
	e->next = p1;
	for(int i = 0; i < n; i++){
		cout << "Input source id:" << endl;
		scanf("%d", p1->cou_id);
		cout << "Input student name:" << endl;
		scanf("%s", p1->stu_id);
		cout << "Input student's source:" << endl;
		scanf("%s", p1->mark);
		e->next = p1;
		e = p1;
		e->next = NULL;
	}
}

void Delch(int a, int b){
	CH *p = f;
	while(p->next != NULL){
		if(p->next->cou_id == a && p->next->stu_id == b){
			CH *q;
			q = p->next;
			p->next = p->next->next;
			delete(q);
			return;
		}
		else{
			p = p->next;
		}
	}
}

void QchMenu(int qid){
	CH *p = f;
	while(p->next != NULL){
		if(p->next->stu_id == qid){
			cout << "course id: " << p->next->cou_id << endl;
			cout << "student id: " << p->next->stu_id << endl;
			cout << "marks: " << p->next->mark << endl;
		}
		else{
			p = p->next;	
		}
	}
	system("pause");
}

void outputch(){
	CH *p = f;
	while(p->next != NULL){
		cout << "course id: " << p->next->cou_id << endl;
		cout << "student id: " << p->next->stu_id << endl;
		cout << "marks: " << p->next->mark << endl;
		p = p->next;
	}
	system("pause");
}

void readch(){
	system("cls");
	fp = fopen("ch.txt","rb");
	f = NULL;
	CH *p1, *p2;
	p1 = p2 = (CH *)malloc(sch);
	int len = 0;
	fscanf(fp,"%d",&p1->cou_id); 
	while(p1->cou_id != 0){
		fscanf(fp,"%d",&p1->stu_id);		
		fscanf(fp,"%d",&p1->mark);
		len++;
		if(len == 1){
			f = p1;
		}
		else{
			p2->next = p1;
		}
		p2 = p1;
		e = p2;
		p1 = (CH *)malloc(sch);
		fscanf(fp,"%d",&p1->cou_id);
		e->next = NULL;
		
	}
	cout << "Read student's course over." << endl;
	system("pause");
}

void savedate_ch(){
	system("cls");
	CH *p = f;
	fp = fopen("ch.txt","wt");
	while(p->next != NULL){
		fprintf(fp, "%d\t", p->cou_id);    		
        fprintf(fp, "%d\t", p->stu_id); 			
		fprintf(fp, "%d\t", p->mark);
		p = p->next;
	}
	fprintf(fp,"0");
	fclose(fp);
	cout << "Save student's course information over." << endl;
	system("pause");
}

int main(){
	menu();
	return 0;
}
