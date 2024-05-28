#include <iostream>
using namespace std;

struct Mahasiswa {
    string npm, nama, jurusan;
    Mahasiswa* next;
};

Mahasiswa* head, * tail, * newNode, * cur, * del;

void createCircularSingleLinkedList(string dataBaru[]) {
    head = new Mahasiswa();
    head->npm = dataBaru[0];
    head->nama = dataBaru[1];
    head->jurusan = dataBaru[2];
    tail = head;
    tail->next = head;
}

//tambah node baru di awalan node sebelumnya jadi ke-2
void addFirst(string data[]) {
    if (head == NULL) {
        cout << "buat likend list dulu" << endl;
    } else {

        newNode = new Mahasiswa;
        newNode->npm = data[0];
        newNode->nama = data[1];
        newNode->jurusan = data[2];
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

//tambah node baru tapi diakhir
void addlast(string data[]) {
    if (head == NULL) {
        cout << "buat likend list dulu" << endl;
    } else {
        newNode = new Mahasiswa;
        newNode->npm = data[0];
        newNode->nama = data[1];
        newNode->jurusan = data[2];
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

//tambah node ditengah
void addMiddle(string data[3], int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!" << endl;
    } else {
        if (posisi <= 1) {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        } else {
            newNode = new Mahasiswa();
            newNode->npm = data[0];
            newNode->nama = data[1];
            newNode->jurusan = data[2];

            // traversing
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

//menghapus node pertama
void removefirst() {
    if (head == NULL) {
        cout << "buat likend list dulu" << endl;
    } else {
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

//menghapus node diakhir
void removelast() {
    if (head == NULL) {
        cout << "buat likend list dulu" << endl;
    } else {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

//menghapus node middle
void removeMiddle(int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!" << endl;
    } else {
        // traversing
        int nomor = 1;
        cur = head;
        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }
}

//mencetak circular
void printCircular() {
    cout << "\t\t\tData Mahasiswa" << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << "| NPM\t\t|\t Nama\t\t\t|\tJurusan\t|" << endl;
    cout << "-----------------------------------------------------------------\n";
    cur = head;
    do {
        cout << "| " << cur->npm << "\t| " << cur->nama << "\t\t\t| " << cur->jurusan << "|" << endl;
        cur = cur->next;
    } while (cur != head);
}

int main() {
    string dataBaru[3] = { "9926171841", "Kurnia Risky Ramadhani", "Teknik Informatika" };
    createCircularSingleLinkedList(dataBaru);
    printCircular();

    string data[3] = { "6626171855", "Bambang Tensioner", "Teknik Informatika" };
    addFirst(data);
    printCircular();

    string data2[3] = { "7726171835", "nopel radiator", "Teknik Informatika" };
    addlast(data2);
    printCircular();

    string data3[3] = { "8826171821", "Adil Turbocharger", "Teknik Informatika" };
    addMiddle(data3, 5);
    printCircular();

    removeMiddle(6);
    printCircular();
}
