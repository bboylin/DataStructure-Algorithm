import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

public class HuffmanTree {
	private Map<Character,Integer> map=new HashMap<Character,Integer>();
	int n=0;
	int tree[][];
	char c[];
	int low=0;
	int high;
	int tempchar;
	Reader reader=null;
	String EncodedStr="";
	File writefile=new File("D:\\compressedFile.txt");
	File outputFile=new File("D:\\decompressedFile.txt");
	FileWriter fileWriter=null;
	File readfile=null;
	//读取，统计，建树，逐字查找，压缩到另一个文件，读取，解压到另一个文件。
	public HuffmanTree(String filename) throws IOException {
		readInitFile(filename);
		buildtree();
		encode();
		Decode();
	}
	public void readInitFile(String filename){//读取，统计
		readfile=new File(filename);
		try {
			reader=new InputStreamReader(new FileInputStream(readfile));
			while((tempchar=reader.read())!=-1){
				if(map.containsKey((char)tempchar)){
					int v=map.get((char)tempchar);
					map.put((char)tempchar,v+1);
				}
				else{
					map.put((char)tempchar,1);
					n++;
				}
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public void buildtree() {//建树
		tree=new int[4][];
		for(int i=0;i<4;i++){
			tree[i]=new int[2*n-1];//value,p,left,right
		}
		c=new char[2*n-1];
		List<Map.Entry<Character,Integer>> list=new ArrayList<Map.Entry<Character,Integer>>(map.entrySet());
		Collections.sort(list,new Comparator<Map.Entry<Character, Integer>>() {

			@Override
			public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
				return o1.getValue()-(o2.getValue());
			}
			
		});
		int t=0;
		for(Map.Entry<Character, Integer> entry:list){
			c[t]=entry.getKey();
			tree[0][t]=entry.getValue();
			tree[1][t]=-1;
			tree[2][t]=-1;
			tree[3][t]=-1;
			t++;
		}
		for(t=n;t<2*n-1;t++){
			c[t]='0';
			tree[1][t]=-1;
			tree[2][t]=-1;
			tree[3][t]=-1;
		}
		low=0;
		high=n;
		do{
			sort(low,high);
			if(high-low>1) mergetree();
		}while(high<(2*n-1)&&high>low&&low>1);
		System.out.println("break!\n");
	}
	public void mergetree() {
		tree[0][high]=tree[0][low]+tree[0][low+1];
		tree[1][low]=high;
		tree[1][low+1]=high;
		tree[2][high]=low;
		tree[3][high]=low+1;
		low=2+low;
		high++;
	}
	public void sort(int low,int high) {
		for(int i=low+1;i<high;i++){
			for(int j=i;(j>low)&&(tree[0][j]>tree[0][j-1]);j--){
				swapnode(j,j-1);
			}
		}
	}
	public void swapnode(int j, int k) {
		int t=tree[2][j];
		if(t!=-1){
			tree[1][t]=k;
		}
		t=tree[3][j];
		if(t!=-1){
			tree[1][t]=k;
		}
		t=tree[2][k];
		if(t!=-1){
			tree[1][t]=j;
		}
		t=tree[3][k];
		if(t!=-1){
			tree[1][t]=j;
		}
		t=tree[1][k];
		if(t!=-1){
			if(tree[2][t]==k){
				tree[2][t]=j;
			}else if(tree[3][t]==k){
				tree[3][t]=j;
			}else{
				System.out.println("the tree is ill\n");
			}
		}
		t=tree[1][j];
		if(t!=-1){
			if(tree[2][t]==j){
				tree[2][t]=k;
			}else if(tree[3][t]==j){
				tree[3][t]=k;
			}else{
				System.out.println("the tree is ill\n");
			}
		}
		for(int i=0;i<4;i++){
			t=tree[i][k];
			tree[i][k]=tree[i][j];
			tree[i][j]=t;
		}
		char ch;
		ch=c[j];
		c[j]=c[k];
		c[k]=ch;
	}
	public void encode() throws IOException {//编码压缩
		try {
			reader=new InputStreamReader(new FileInputStream(readfile));
			fileWriter=new FileWriter(writefile);
			String s="";
			while((tempchar=reader.read())!=-1){
				for(int i=0;i<n;i++){
					if(c[i]==(char)tempchar){
						int p=tree[1][i];
						int q=i;
						while(p!=-1){
							if(tree[2][p]==q){
								s+="0";
							}
							else if(tree[3][p]==q){
								s+="1";
							}else{
								s+="2";
							}
							q=p;
							p=tree[1][q];
						}
						if(s!=""){
							StringBuffer sb=new StringBuffer(s);
							EncodedStr+=sb.reverse().toString();
							s="";
							System.out.println(EncodedStr+"\n");
						}
						break;
					}
				}
			}
			if(EncodedStr!=""){
				fileWriter.write(EncodedStr);
			}
			fileWriter.flush();
			fileWriter.close();
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		
	}
	public void Decode() throws IOException {//解码解压缩
		fileWriter=new FileWriter(outputFile);
		int x=2*n-2;
		for(int i=0;i<EncodedStr.length();i++){
			tempchar=EncodedStr.charAt(i);
			if(c[x]=='0'){
				if(tempchar==48){
					x=tree[2][x];
				}else if(tempchar==49){
					x=tree[3][x];
				}else{
					System.out.println("错误：包含不为0或1的数\n");
				}
			}else{
				fileWriter.write(c[x]);
				x=2*n-2;
				if(tempchar==48){
					x=tree[2][x];
				}else if(tempchar==49){
					x=tree[3][x];
				}else{
					System.out.println("错误：包含不为0或1的数\n");
				}
			}
		}
		fileWriter.flush();
		fileWriter.close();
	}
	public static void main(String[] args) throws IOException {
		HuffmanTree huffmanTree=new HuffmanTree("D:\\Huffman.txt");
	}

}
