/*
Bài 4.1: Đảo ngược một danh sách liên kết đơn

Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết:

Thêm một phần tử vào đầu danh sách liên kết
In danh sách
Đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng thêm O(1))
*/

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// push a new element to the beginning of the list
Node* prepend(Node* head, int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    return temp;
}
// print the list content on a line
void print(Node* head)
{
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
// return the new head of the reversed List
Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int main()
{
    int n, u;
    std::cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        std::cin >> u;
        head = prepend(head, u);
    }
    std::cout << "Original list: ";
    print(head);
    head = reverse(head);
    std::cout << "Reversed list: ";
    print(head);
    return 0;
}
