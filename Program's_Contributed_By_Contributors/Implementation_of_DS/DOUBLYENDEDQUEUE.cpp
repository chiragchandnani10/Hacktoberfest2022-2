#include<iostream>
#include<string>
using namespace std;
class queue{
    public:
    int front;
    int rear;
    int val;
    int size;
    int *arr;
    queue(){
        front = -1;
        rear = -1;
        size = 5;
        arr = new int[size];
    }
    
    void pushfront(int x){
        if(((front-1)%size==rear)||(front==0&&rear==size-1)){
            cout<<"Queue full"<<endl;
            exit(0);

        }
        else if(front==-1&&rear==-1){
            front=0;
            rear = 0;
            arr[front]=x;
        }
        else if(front==0){
            front = size-1;
            arr[front]=x;


        }
        else{
            front--;
            arr[front]=x;
        }

    }

    void enqueuerear(int y){
        if(((front==0)&&(rear==size-1))||((rear+1)%size==front)){
            cout<<"Queue full";
            exit(0);

        }
        else if(front==-1&&rear==-1){
            front=rear=0;
            arr[rear]=y;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=y;
        }
    }

    void popfront(){
        if(((front==-1)&&(rear==-1))){
            cout<<"Empty";
            exit(0);
        }
        else if(front==rear){
            cout<<"Item deleted is"<<arr[front];
            front = -1;
            rear = -1;
        }
        else{
            cout<<"Item deleted is"<<arr[front];
            front = (front+1)%size;
            
            

        }
    }

    void poprear(){
        if((front==-1)&&(rear==-1)){
            cout<<"Empty";
        }
        else if(front==rear){
            cout<<"Deleted is"<<arr[rear];
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            cout<<"Deleted is"<<arr[rear];
            rear=size-1;
            

        }
        else{
            cout<<"Deleted is"<<arr[rear];
            rear--;
        }
    }

    void traverse(){
        int i=front;
        if(front==-1&&rear==-1){
            cout<<"Empty";
        }
        else{
            while(i!=rear+1){
                cout<<"values"<<arr[i]<<endl;
                i = (i+1)%size;
            }

        }
    }

};
int main(){

    queue q;
    q.pushfront(23);
    q.pushfront(45);
    q.pushfront(56);
    q.traverse();
    q.popfront();
    q.traverse();
}