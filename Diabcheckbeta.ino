#include <Nextion.h> 
NexCheckbox C0 = NexCheckbox(2,2,"c0"); 
NexCheckbox C1 = NexCheckbox(2,4,"c1"); 
NexCheckbox C2 = NexCheckbox(2,8,"c2"); 
NexCheckbox C3 = NexCheckbox(2,10,"c3"); 
NexCheckbox C4 = NexCheckbox(2,15,"c4"); 
NexCheckbox C5 = NexCheckbox(2,14,"c5"); 
NexCheckbox C6 = NexCheckbox(2,20,"c6"); 
NexCheckbox C7 = NexCheckbox(2,21,"c6"); 
NexCheckbox C8 = NexCheckbox(2,22,"c8"); 
NexCheckbox C9 = NexCheckbox(2,23,"c9"); 
NexCheckbox C10 = NexCheckbox(2,27,"c10"); 
NexCheckbox C11 = NexCheckbox(2,28,"c11"); 
NexButton Results = NexButton(3,4,"b1"); 
NexText t1 = NexText(3,6,"t1"); 
NexText t2 = NexText(3,7,"t2");
NexText t3 = NexText(3,8,"t3");
NexText t5 = NexText(3,9,"t5 ");

 int a0=0;int a1=0;int a2=0;int a3=0;int a4=0;int a5=0;int a6=0;int a7=0;int a8=0;int a9=0;      
 int a10=0;int a11=0;int a12=0;int a13=0;int a14=0;int a15=0;int a16=0;int a17=0;int a18=0;int a19=0;

NexTouch *nex_listen_list[] = {
&C0,
&C1,
&C2,
&C3,
&C4,
&C5,
&C6,
&C7,
&C8,
&C9,
&C10,
&C11,
&Results,
NULL
};

void C0PopCallback(void *ptr){
       a0=1;
}
void C1PopCallback(void *ptr){
       a1=1;
}
void C2PopCallback(void *ptr){
       a2=1;
}
void C3PopCallback(void *ptr){
       a3=1;
}
void C4PopCallback(void *ptr){
       a4=1;
}
void C5PopCallback(void *ptr){
       a5=1;
}
void C6PopCallback(void *ptr){
       a6=1;
}
void C7PopCallback(void *ptr){
      a7=1;
}
void C8PopCallback(void *ptr){
       a8=1;
}
void C9PopCallback(void *ptr){
       a9=1;
}
void C10PopCallback(void *ptr){
       a10=1;
}
void C11PopCallback(void *ptr){
       a11=1;
}

void ResultsPopCallback(void *ptr){
       if(a0==1&&a1==1&&a2==1&&a9==1)
       {
        t1.setText ("You might be suffering from");
        t2.setText ("'TYPE-1 DIABETES'.");
        t3.setText ("The system has detected this");
        t5.setText ("with maximum probability");
       }

       else if(a4==1&&a5==1&&a11==1&&a9==1)
       {
        t1.setText ("You might be suffering from");
        t2.setText ("'TYPE-1 DIABETES'.");
        t3.setText ("The system has detected this");
        t5.setText ("with 50% probability.");
       }


       else
       {
        t1.setText ("Not Available in Database");
        
        t3.setText ("No Disease Detected");
       }
       
       a0=0;a1=0;a2=0;a3=0;a4=0;a5=0;a6=0;a7=0;a8=0;a9=0;      
       a10=0;a11=0;a12=0;a13=0;a14=0;a15=0;a16=0;a17=0;a18=0;a19=0;
}

void setup() {
  Serial.begin(9600);
 nexInit();
 C0.attachPop(C0PopCallback,&C0);
 C1.attachPop(C1PopCallback,&C1);
 C2.attachPop(C2PopCallback,&C2);
 C3.attachPop(C3PopCallback,&C3);
 C4.attachPop(C4PopCallback,&C4);
 C5.attachPop(C5PopCallback,&C5);
 C6.attachPop(C6PopCallback,&C6);
C7.attachPop(C7PopCallback,&C7);
 C8.attachPop(C8PopCallback,&C8);
 C9.attachPop(C9PopCallback,&C9);
 C10.attachPop(C10PopCallback,&C10);
 C11.attachPop(C11PopCallback,&C11);
 Results.attachPop(ResultsPopCallback,&Results); 
}

void loop() {
  nexLoop(nex_listen_list);
}
