//
// Created by  wangchao on 2020/6/8.
//


#include <iostream>
#include "LinkedList.h"


//node的创建，这里巩固一下static_cast？？
Node_* make(int data){
    //分配内存空间，类似于new
    Node_* node = static_cast<Node_ *>(malloc(sizeof(Node_)));
    assert(node != NULL);
    node->data = data;
    node->next = nullptr;
    return node;
}


void myfree(Node_* node){
    free(node);
    node = NULL;
}

void visit(Node_* node){
    assert(node != NULL);
    //打印node
    printf("%p---->>>>%d",node, node->data);
}

void print(LinkedList_* list){
    printf("------list-------");

    printf("length %d \n", list->length);

    //打印head
    printf("head--->>>[%p, %d]\n", list->head, list->head->data);

    //打印中间node
    Node_* current = list->head->next;
    //判断是否是tail
    while(current != list->tail){
        printf("head-->>>[%p, %d]\n", current, current->data);
        current = current->next;
    }

    //打印tail
    printf("tail->>>[%p, %d]\n", list->tail, list->tail->data);
}

LinkedList_* create(){
    LinkedList_* linkedList = static_cast<LinkedList_ *>(malloc(sizeof(LinkedList_)));
    assert(linkedList != NULL);
    linkedList->length = 0;
    linkedList->head = make(0);
    linkedList->tail = make(0);
    linkedList->head->next = linkedList->tail; //初始化的时候是head指向tail
    return linkedList;
}

void append(LinkedList_* linkedList, int data){
    linkedList->tail->data = data;
    //新建临时data为0的node，作为新的tail
    Node_* node = make(0);
    //旧的tail指向新的tail　
    linkedList->tail->next = node;
    linkedList->tail = node;
    linkedList->length += 1;
}

void deleteLastNth(LinkedList_* list, int n){
    assert(list != NULL);
    Node_* fast = list->head;
    Node_* slow = list->head;
    int count = 0;
    //删除倒数第n个，因为有head和tail，所以是n+1
    while(count != n + 1){
        fast = fast->next;
        count++;
    }

    while(fast != list->tail){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
}

/**
 * 思路：将奇数链表放在一个链表里面，偶数放在另外一个里面，偶数连接到奇数列表后面
 * */
void oddEvenList(LinkedList_* list){
    assert(list != NULL);
    Node_ * odd = list->head;
    Node_* even = list->head->next;
    Node_* even_head = even;//奇数链表

    while (even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head;
}

void reverse(LinkedList_* list){
    assert(list != NULL);
    Node_* pre = list->head;
    Node_* current = list->head->next;
    while(current != NULL){
        //保存当前结点的下一个结点，以免链表断裂 
        Node_* tmp = current->next;
        current->next = pre;
        pre = current;
        current = tmp;
    }
    Node_* node = list->head;
    list->head = list->tail;
    list->tail = node;
}


void list_test(){
    LinkedList_* list = create();
    print(list);

    append(list, 50);
    append(list, 60);
    append(list, 70);
    print(list);

}

int main(){
    list_test();
}
