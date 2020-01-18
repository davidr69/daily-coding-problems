class BitArr {
private:
	unsigned char *data;
	int len; // number of bytes representing positions
	int bits; // size of initial request
public:
	void init(int size);
	void set(const int pos, const int val);
	int get(int pos);
	void display(void);
};
