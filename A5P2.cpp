#include <iostream>

using namespace std;

class Node {
    public:
        Node(double theData, Node* theLink) : data(theData), link(theLink){}
        Node* getLink() const { return link; }
        double getData() { return data; }
        void setData(double theData) { data = theData; }
        void setLink(Node* theLink) { link = theLink; }
    private:
        double data;
        Node *link;
};

typedef Node* NodePtr;

class LinkList {
    public:
        LinkList(): head(NULL){}
        void add(double theData);
        void disp();
        NodePtr searchL(int nth);
        int searchL(double dataVal);
        void del();
        void stats();
    private:
        NodePtr head;
};

void LinkList::add(double theData){
    cout << "Enter data value to add: ";
    cin >> theData;

    if (head == NULL){
        head = new Node(theData, NULL);
    }
    else {
        if (head->getData() > theData){
            head = new Node(theData,head);
        }
        else {
            NodePtr here = head;
            NodePtr afterMe;
            while (here->getData() < theData && here->getLink() != NULL) {
                afterMe = here;
                here = here->getLink();
            }
            if (here->getData() > theData)
                afterMe->setLink(new Node(theData,afterMe->getLink()));
            else
                here->setLink(new Node(theData,here->getLink()));
        }

    }
}
void LinkList::disp(){
    if(head == NULL){
        cout << "Empty list.\n";
        return;
    }

    NodePtr output = head;
    while (output != NULL){
        cout << output->getData() << endl;
        output =output->getLink();
    }
}

int LinkList::searchL(double dataVal){
    if(head == NULL){
        cout << "Empty list.\n";
        return 0;
    }

    int nth = 1;
    NodePtr found = head;

    while(found->getData() != dataVal && found->getLink() != NULL){
        nth++;
        found = found->getLink();
    }
    if(found->getData() == dataVal)
        return nth;
    else
        return 0;
}

NodePtr LinkList::searchL(int nth){
    if(head == NULL){
        cout << "Empty list.\n";
        return 0;
    }
    int c = 1;
    NodePtr found = head;

    while (found->getLink() != NULL && c != nth){
        found = found->getLink();
        c++;
    }
    if (c == nth){
        return found;
    }
    else {
        return NULL;
    }

}

void LinkList::del(){
    if(head == NULL){
        cout << "Empty list.\n";
        return;
    }

    int nth;
    cout << "Enter item position number to delete: ";
    cin >> nth;
    int c = 1;
    NodePtr discard = head;
    NodePtr before, next;
    if (nth == 1){
        if (discard->getLink() == NULL){
            head = NULL;
            delete discard;
            return;
        }
        else {
            next = discard->getLink();
            head = next;
            delete discard;
            return;
        }
    }

    while (discard->getLink() != NULL && c != nth){
        before = discard;
        discard = discard->getLink();
        next = discard->getLink();
        c++;
    }
    if (c == nth){
        before->setLink(next);
        delete discard;
    }
    else
        cout << "There are less than " << nth << " terms on the list"
             << " no deletion made\n";

}
void LinkList::stats(){
    if(head == NULL){
        cout << "Empty list.\n";
        return;
    }

	double sum = 0, mean, median;
	NodePtr before, next = head;
	int c1 = 0, c2 = 0;

	while (next != NULL)
	{
		sum += next->getData();
		next = next->getLink();
		c1++;
	}
	mean = sum / c1;
    next = head;
	if (c1 % 2 == 0){
        while (next != NULL && c2 != c1/2){
            before = next;
            next = next->getLink();
            c2++;
        }
        median = (before->getData() + next->getData()) / 2;
    }
	else {
        while (next != NULL && c2 != (c1/2)+1){
            before = next;
            next = next->getLink();
            c2++;
        }
        median = before->getData();
	}
	cout << "LIST STATISTICS\n";
	cout << "Number of items in list = " << c1 << endl;
	cout << "Average = " << mean << endl;
	cout << "Median = " << median << endl << endl;

}


int main() {

    int nth, opt;
    LinkList l;
    double number;
    NodePtr n;

  

    do {
        cout << "\nMake a selection:\n"
             << "1 - Add a value (decimal number)\n"
             << "2 - Search for a value\n"
             << "3 - Find the nth value\n"
             << "4 - Delete the nth value\n"
             << "5 - Display list statistics (count, mean, median)\n"
             << "6 - Display the list\n"
             << "7 - Exit the program\n"
             << "=> ";
        cin >> opt;

        switch(opt){
            case 1:
                l.add(number);
                break;
            case 2:
                cout << "Enter data value to search for: ";
                cin >> number;
                if(l.searchL(number))
                    cout << number << " is in position "
                         << l.searchL(number) << endl;
                else
                    cout << number << " is not on the list\n";
                break;
            case 3:
                cout << "Enter position number to find: ";
                cin >> nth;
                if(l.searchL(nth)) {
                    n = l.searchL(nth);
                    cout << "Value of position " << nth << " is "
                         << n->getData() << endl;
                }
                else
                    cout << "No position " << nth << " on the list.\n";
                break;
            case 4:
                l.del();
                break;
            case 5:
                l.stats();
                break;
            case 6:
                l.disp();
                break;
            case 7:
                cout << "see ya next time \n";
                break;
        }

    }while(opt != 7);

}


