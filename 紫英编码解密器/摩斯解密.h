struct Tree
{
	Tree *left, *right;
	char flag, data;
	Tree(char f, char d)
	{
		flag = f;
		data = d;
		left = right = NULL;
	}
};

struct Halftree
{
	Tree *root;
	Halftree(char f, char d);
	Tree *findf(char flag,char position);
	Tree *findd(Tree *node,char position);
	void mkleft(char data, char position);
	void mkright(char data, char position);
};
Halftree::Halftree(char f, char d)
{
	root = new Tree(f, d);
}
Tree * Halftree::findf(char flag,char position)					//寻找相对data为position的结点的下一个flag摩斯码（./-)对应结点，position即结点对应字符
{
	if (flag == '-')
		return findd(root, position)->left;
	if (flag == '.')
		return findd(root, position)->right;
	return NULL;
}
Tree * Halftree::findd(Tree *node,char position)				//寻找data等于position的结点并返回
{
	if (node == NULL)
		return NULL;
	if (node->data == position)
		return node;
	Tree *p = node;
	if (findd(p->left, position) != NULL)
		return findd(p->left, position);
	else
		return findd(p->right, position);

}

void Halftree::mkleft(char data, char position)
{
	Tree *tree = new Tree('-', data);
	findd(root, position)->left=tree;
	
}
void Halftree::mkright(char data, char position)
{
	Tree *tree = new Tree('.', data);
	findd(root, position)->right=tree;
}

Halftree G_MOSI('a', 'a');						//创建全局对象

void mkmosi()												//以摩斯映射初始化哈弗曼树
{
	G_MOSI.mkleft('T', 'a');
	G_MOSI.mkleft('M', 'T');
	G_MOSI.mkleft('O', 'M');
	G_MOSI.mkleft('b', 'O');
	G_MOSI.mkleft('0', 'b');
	G_MOSI.mkright('9', 'b');
	G_MOSI.mkright('c', 'O');
	G_MOSI.mkright('8', 'c');
	G_MOSI.mkright('G', 'M');
	G_MOSI.mkright('Z', 'G');
	G_MOSI.mkright('7', 'Z');
	G_MOSI.mkleft('Q', 'G');
	G_MOSI.mkright('N', 'T');
	G_MOSI.mkright('D', 'N');
	G_MOSI.mkright('B', 'D');
	G_MOSI.mkright('6', 'B');
	G_MOSI.mkleft('X', 'D');
	G_MOSI.mkleft('K', 'N');
	G_MOSI.mkright('C', 'K');
	G_MOSI.mkleft('Y', 'K');
	G_MOSI.mkright('E', 'a');
	G_MOSI.mkright('I', 'E');
	G_MOSI.mkright('S', 'I');
	G_MOSI.mkright('H', 'S');
	G_MOSI.mkright('5', 'H');
	G_MOSI.mkleft('4', 'H');
	G_MOSI.mkleft('V', 'S');
	G_MOSI.mkleft('3', 'V');
	G_MOSI.mkleft('U', 'I');
	G_MOSI.mkleft('d', 'U');
	G_MOSI.mkleft('2', 'd');
	G_MOSI.mkright('F', 'U');
	G_MOSI.mkleft('A', 'E');
	G_MOSI.mkleft('W', 'A');
	G_MOSI.mkleft('J', 'W');
	G_MOSI.mkleft('1', 'J');
	G_MOSI.mkright('P', 'W');
	G_MOSI.mkright('R', 'A');
	G_MOSI.mkright('L', 'R');
}								
CString Mosi(CString code)
{
	mkmosi();
	CString clear;
	int lofcode = code.GetLength();
	char temp='a';
	for (int i = 0; i < lofcode;i++)
	{
		if (G_MOSI.findf((char)code[i], temp))
			temp = G_MOSI.findf((char)code[i], temp)->data;			//对摩斯码解密
		else temp = '?';
	}
	clear.Format(_T("%c"), temp);
	return clear;
}