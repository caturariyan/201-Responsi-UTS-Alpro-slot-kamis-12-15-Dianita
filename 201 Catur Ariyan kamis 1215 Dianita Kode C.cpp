// kode soal C
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Barang {
	string namaBarang;
	int harga;
	int jumlah;
	string kode, alamat, eks;
	int total = 0;
};

class Toko {
private:
	string nama = "caturariyan"	;
	string nim = "201";
	int saldo = 0;
	vector<Barang> brg;
	bool protek = false;
	bool vou = false;
	bool gra = false;

public:
	void login() {
		while(true) {
			string user, pass;
			cout << "Username	: "; 
			cin >> user;
			cout << "Password	: "; 
			cin >> pass;
			
			if (user == nama && pass == nim) {
				cout << "Selamat Anda Berhasil Login.\n\n";
				break;
			} else {
				cout << "Username dan Password tidak sesuai\n\n";
			}
		}
	}
	
	void cekSaldo() {
		cout << "\nSaldo Anda Rp " << saldo << endl;
	}
	
	void tambahSaldo() {
		int tbhSaldo;
		cout << "\nMasukkan jumlah saldo yang ingin Anda tambahkan : Rp ";
		cin >> tbhSaldo;
		
		saldo += tbhSaldo;
		cout << "\nSaldo Anda Rp " << saldo << endl;
	}
	
	void tambahBarang() {
		Barang b;
		
		char lagi;
		do {
		cout << "\nMasukkan Kode Barang	: ";
		cin >> b.kode;
		cout << "Masukkan Nama Barang	: ";
		cin >> b.namaBarang;
		cout << "Masukkan Harga Barang	: ";
		cin >> b.harga;
		cout << "Masukkan Jumlah Barang	: ";
		cin >> b.jumlah;
		
		int ttlHarga = b.harga * b.jumlah;
		b.total += ttlHarga;
		
		brg.push_back(b);
		cout << b.namaBarang << " berhasil ditambahkan ke keranjang\n";
		
		cout << "Apakah Anda ingin menambahkan barang lagi (y/n) : ";
		cin >> lagi; 
		
		} while (lagi == 'Y' || lagi == 'y');
	}
	
	void hapusBarang() {
		Barang b;
		keranjang();
		string kodeHps;
		cout << "\nMasukkan kode barang yang ingin dihapus : ";
		cin >> kodeHps;
		
		for (int i = 0; i < brg.size(); ++i) {
			if (brg[i].kode == kodeHps) {
				cout << brg[i].namaBarang << " berhasil dihapus dari keranjang\n";
				brg.erase(brg.begin() + i);
			}
		}
	}
	
	void keranjang() {
		Barang b;
		cout << "\nKode	Nama	Harga	Jumlah\n";
		for (int i = 0; i < brg.size(); ++i) {
			cout << brg[i].kode << "	" << brg[i].namaBarang << "	" << brg[i].harga << "	" << brg[i].jumlah << endl;
		}
	}
	
	void alamat() {
		Barang b;
		cout << "Masukkan Alamat Penerima	: ";
		cin >> b.alamat;
		
		brg.push_back(b);
		cout << b.alamat << " berhasil ditambahkan sebagai Alamat Penerima\n";

	}
	
	void voucher() {
		Barang b;
		char vcr;	
		cout << "\nAnda ingin menambahkan voucher diskon 20% ? (y/n) : ";
		cin >> vcr;
		
		if (vcr == 'Y' || vcr == 'y') {
			if (b.total > 50000) {
				vou = true;
				cout << "\nVoucher berhasil digunakan\n";
			} else {
				cout << "\nVoucher Diskon 20% hanya bisa dipakai pada total pembelian diatas Rp 50.000";
				
			}
		} else {
			menu();
		}
	}
	
	void proteksi() {
		Barang b;
		char pro;
		cout << "\nAnda ingin menambahkan proteksi keamanan ? (y/n) : ";
		cin >> pro;
		
		if (pro == 'Y' || pro == 'y') {
			protek = true;
			cout << "\nProteksi keamanan berhasil ditambahkan.\n";
		} else {
			menu();
		}
	}
	
	void gratong() {
		Barang b;
		char g;
		cout << "\nAnda ingin menambahkan gratis ongkir ? (y/n) : ";
		cin >> g;
		
		if (g == 'Y' || g == 'y') {
			gra = true;
			cout << "\nGratis ongkir berhasil ditambahkan berhasil ditambahkan.\n";
		} else {
			menu();
		}
	}
	
	void ekspedisi() {
		Barang b;
		cout << "\nPilih Ekspedisi (JNT/JNE/EXPRESS)	: ";
		cin >> b.eks;
		
		brg.push_back(b);
		cout << b.eks << " berhasil dipilih sebagai Ekspedisi Pengiriman\n";
	}
	
	void invoice() {
		Barang b;
		int ttl;
		
		ofstream file("struk.txt");
		file << "Nama Pembeli : " << nama << endl;
		file << "Alamat Penerima : " << b.alamat << endl;
		file << "Voucher : " << (vou ? "Berhasil ditambahkan" : "Tanpa Voucher") << endl;
		file << "Proteksi keamanan : " << (protek ? "Menambahkan proteksi keamanan" : "Tanpa proteksi keamanan") << endl;
		file << "Gratis Ongkir : " << (gra ? "Berhasil ditambahkan" : "Tanpa Gratis Ongkir") << endl;
		file << "Ekspedisi Pengiriman : " << b.eks << endl;
		file << "Detail Pesanan : " << endl;
		for (int i = 0; i < brg.size(); i++) {
			file << brg[i].kode << " - " << brg[i].namaBarang << " - Rp " << brg[i].harga << " - " << brg[i].jumlah << " pcs" << endl;
			ttl = brg[i].harga * brg[i].jumlah;
			b.total += ttl;
		}
		
		if (vou == true) {
			b.total *= 0.5;
		}
		
		file << "Total yang harus dibayarkan : Rp " << b.total << endl;
		file.close();
		if (saldo < ttl) {
			cout << "Saldo Anda kurang, Silahkan top up dulu\n";
		} else {
			cout << "\nTotal yang harus dibayarkan : Rp " << b.total;
			cout << "\nInvoice berhasil disimpan pada struk.txt\n";
		}
		
	}
	
	void menu() {
		int pilih;
		do {
			cout << "\n================================\n";
			cout << "	Menu Marketplace\n";
			cout << "================================\n";
			cout << "1. Cek Saldo\n";
			cout << "2. Tambah Saldo\n";
			cout << "3. Tambah Barang\n";
			cout << "4. Hapus Barang\n";
			cout << "5. Lihat Keranjang\n";
			cout << "6. Tambah Alamat\n";
			cout << "7. Voucher / Diskon\n";
			cout << "8. Proteksi / Asuransi\n";
			cout << "9. Gratis Ongkir\n";
			cout << "10. Pilih Ekspedisi Voucher / Diskon\n";
			cout << "11. Lihat Invoice\n";
			cout << "0. Keluar\n";
			
			cout << "Masukkan Pilihan Anda : ";
			cin >> pilih;
			
			if (pilih == 1) {
				cekSaldo();
			} else if (pilih == 2) {
				tambahSaldo();
			} else if (pilih == 3) {
				tambahBarang();
			} else if (pilih == 4) {
				hapusBarang();
			} else if (pilih == 5) {
				keranjang();
			} else if (pilih == 6) {
				alamat();
			} else if (pilih == 7) {
				voucher();
			} else if (pilih == 8) {
				proteksi();
			} else if (pilih == 9) {
				gratong();
			} else if (pilih == 10) {
				ekspedisi();
			} else if (pilih == 11) {
				invoice();
			} else {
				cout << "\nPilihan Anda tidak ada.\n";
			}
			
			
		} while (pilih != 0);
	}
};

int main() {
	Toko t;
	
	t.login();
	t.menu();
	
	
	return 0;
}


