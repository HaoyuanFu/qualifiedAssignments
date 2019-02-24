package sort;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import org.junit.Assert;
import org.junit.Test;

public class SortTest {
	@Test
	public void testSortInsert() throws IOException{
		File file=new File("data/a1_in.txt");
		BufferedReader br=new BufferedReader(new FileReader(file));
		String[] content=new String[5];
		int n=0;
		String s0;
		while((s0=br.readLine()) != null){
			content[n]=s0;
			n++;
			//System.out.println(content);
		}
		Job[]jobs1=new Job[16];
		Job[]jobs2=new Job[64];
	Job[]jobs3=new Job[256];
		Job[]jobs4=new Job[1024];
		Job[]jobs5=new Job[4096];
		String[]s1=content[0].split(",");
		int idx=0;
		for(int i=0;i<s1.length;){
			String tmp1=s1[i].substring(1);
			i++;
			String tmp2=s1[i].substring(0, s1[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs1[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s2=content[1].split(",");
		idx=0;
		for(int i=0;i<s2.length;){
			String tmp1=s2[i].substring(1);
			i++;
			String tmp2=s2[i].substring(0, s2[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs2[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s3=content[2].split(",");
	 idx=0;
		for(int i=0;i<s3.length;){
			String tmp1=s3[i].substring(1);
			i++;
			String tmp2=s3[i].substring(0, s3[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs3[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s4=content[3].split(",");
	 idx=0;
		for(int i=0;i<s4.length;){
			String tmp1=s4[i].substring(1);
			i++;
			String tmp2=s4[i].substring(0, s4[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs4[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s5=content[4].split(",");
		 idx=0;
		for(int i=0;i<s5.length;){
			String tmp1=s5[i].substring(1);
			i++;
			String tmp2=s5[i].substring(0, s5[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs5[idx]=new Job(id,seconds);
			//System.out.println(jobs5[idx]);
			idx++;
		}
		
		long time1=System.currentTimeMillis();
		Insertion.sortInsert(jobs1);
		
		Insertion.sortInsert(jobs2);
		Insertion.sortInsert(jobs3);
		Insertion.sortInsert(jobs4);
		Insertion.sortInsert(jobs5);
		long time2=System.currentTimeMillis();
		BufferedWriter bw=new BufferedWriter(new FileWriter("data/a1_sortInsertor_out.txt"));
		for(int i=0;i<jobs1.length;i++){
			bw.write(jobs1[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs2.length;i++){
			bw.write(jobs2[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs3.length;i++){
			bw.write(jobs3[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs4.length;i++){
			bw.write(jobs4[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		for(int i=0;i<jobs5.length;i++){
			bw.write(jobs5[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		System.out.println(time2-time1);
	}
	
	@Test
	public void testSortComarable() throws IOException{
		File file=new File("data/a1_in.txt");
		BufferedReader br=new BufferedReader(new FileReader(file));
		String[] content=new String[5];
		int n=0;
		String s0;
		while((s0=br.readLine()) != null){
			content[n]=s0;
			n++;
			//System.out.println(content);
		}
		Comparable[]jobs1=new Job[16];
		Comparable[]jobs2=new Job[64];
		Comparable[]jobs3=new Job[256];
		Comparable[]jobs4=new Job[1024];
		Comparable[]jobs5=new Job[4096];
		String[]s1=content[0].split(",");
		int idx=0;
		for(int i=0;i<s1.length;){
			String tmp1=s1[i].substring(1);
			i++;
			String tmp2=s1[i].substring(0, s1[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs1[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s2=content[1].split(",");
		idx=0;
		for(int i=0;i<s2.length;){
			String tmp1=s2[i].substring(1);
			i++;
			String tmp2=s2[i].substring(0, s2[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs2[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s3=content[2].split(",");
	 idx=0;
		for(int i=0;i<s3.length;){
			String tmp1=s3[i].substring(1);
			i++;
			String tmp2=s3[i].substring(0, s3[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs3[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s4=content[3].split(",");
	 idx=0;
		for(int i=0;i<s4.length;){
			String tmp1=s4[i].substring(1);
			i++;
			String tmp2=s4[i].substring(0, s4[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs4[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s5=content[4].split(",");
		 idx=0;
		for(int i=0;i<s5.length;){
			String tmp1=s5[i].substring(1);
			i++;
			String tmp2=s5[i].substring(0, s5[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs5[idx]=new Job(id,seconds);
			idx++;
		}
		
		long time1=System.currentTimeMillis();
		Insertion.sortComparable(jobs1,16);
		Insertion.sortComparable(jobs2,64);
		Insertion.sortComparable(jobs3,256);
		Insertion.sortComparable(jobs4,1024);
		Insertion.sortComparable(jobs5,4096);
		long time2=System.currentTimeMillis();
		
		BufferedWriter bw=new BufferedWriter(new FileWriter("data/a1_sortComparable_out.txt"));
		for(int i=0;i<jobs1.length;i++){
			bw.write(jobs1[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs2.length;i++){
			bw.write(jobs2[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs3.length;i++){
			bw.write(jobs3[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs4.length;i++){
			bw.write(jobs4[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		for(int i=0;i<jobs5.length;i++){
			bw.write(jobs5[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		
		
		
		
		
		
		System.out.println(time2-time1);
	}
	@Test
	public void testInsertBinary() throws IOException{
		File file=new File("data/a1_in.txt");
		BufferedReader br=new BufferedReader(new FileReader(file));
		String[] content=new String[5];
		int n=0;
		String s0;
		while((s0=br.readLine()) != null){
			content[n]=s0;
			n++;
			//System.out.println(content);
		}
		Comparable[]jobs1=new Job[16];
		Comparable[]jobs2=new Job[64];
		Comparable[]jobs3=new Job[256];
		Comparable[]jobs4=new Job[1024];
		Comparable[]jobs5=new Job[4096];
		String[]s1=content[0].split(",");
		int idx=0;
		for(int i=0;i<s1.length;){
			String tmp1=s1[i].substring(1);
			i++;
			String tmp2=s1[i].substring(0, s1[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs1[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s2=content[1].split(",");
		idx=0;
		for(int i=0;i<s2.length;){
			String tmp1=s2[i].substring(1);
			i++;
			String tmp2=s2[i].substring(0, s2[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs2[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s3=content[2].split(",");
	 idx=0;
		for(int i=0;i<s3.length;){
			String tmp1=s3[i].substring(1);
			i++;
			String tmp2=s3[i].substring(0, s3[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs3[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s4=content[3].split(",");
	 idx=0;
		for(int i=0;i<s4.length;){
			String tmp1=s4[i].substring(1);
			i++;
			String tmp2=s4[i].substring(0, s4[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs4[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s5=content[4].split(",");
		 idx=0;
		for(int i=0;i<s5.length;){
			String tmp1=s5[i].substring(1);
			i++;
			String tmp2=s5[i].substring(0, s5[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs5[idx]=new Job(id,seconds);
			//System.out.println(jobs5[idx]);
			idx++;
		}
		//System.out.println(1);
		long time1=System.currentTimeMillis();
		Insertion.sortBinary(jobs1,16);
		Insertion.sortBinary(jobs2,64);
		Insertion.sortBinary(jobs3,256);
		Insertion.sortBinary(jobs4,1024);
		Insertion.sortBinary(jobs5,4096);
		long time2=System.currentTimeMillis();
		
		BufferedWriter bw=new BufferedWriter(new FileWriter("data/a1_InsertBinary_out.txt"));
		for(int i=0;i<jobs1.length;i++){
			bw.write(jobs1[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs2.length;i++){
			bw.write(jobs2[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs3.length;i++){
			bw.write(jobs3[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs4.length;i++){
			bw.write(jobs4[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		for(int i=0;i<jobs5.length;i++){
			bw.write(jobs5[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		
		
		
		
		
		
		
		System.out.println(time2-time1);
	}
	@Test
	public void Merge() throws IOException{
		File file=new File("data/a1_in.txt");
		BufferedReader br=new BufferedReader(new FileReader(file));
		String[] content=new String[5];
		int n=0;
		String s0;
		while((s0=br.readLine()) != null){
			content[n]=s0;
			n++;
			//System.out.println(content);
		}
		Comparable[]jobs1=new Job[16];
		Comparable[]jobs2=new Job[64];
	Comparable[]jobs3=new Job[256];
		Comparable[]jobs4=new Job[1024];
		Comparable[]jobs5=new Job[4096];
		String[]s1=content[0].split(",");
		int idx=0;
		for(int i=0;i<s1.length;){
			String tmp1=s1[i].substring(1);
			i++;
			String tmp2=s1[i].substring(0, s1[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs1[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s2=content[1].split(",");
		idx=0;
		for(int i=0;i<s2.length;){
			String tmp1=s2[i].substring(1);
			i++;
			String tmp2=s2[i].substring(0, s2[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs2[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s3=content[2].split(",");
	 idx=0;
		for(int i=0;i<s3.length;){
			String tmp1=s3[i].substring(1);
			i++;
			String tmp2=s3[i].substring(0, s3[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs3[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s4=content[3].split(",");
	 idx=0;
		for(int i=0;i<s4.length;){
			String tmp1=s4[i].substring(1);
			i++;
			String tmp2=s4[i].substring(0, s4[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs4[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s5=content[4].split(",");
		 idx=0;
		for(int i=0;i<s5.length;){
			String tmp1=s5[i].substring(1);
			i++;
			String tmp2=s5[i].substring(0, s5[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs5[idx]=new Job(id,seconds);
			//System.out.println(jobs5[idx]);
			idx++;
		}
		
		long time1=System.currentTimeMillis();
		
		Merge.sortMerge(jobs1, 16);
		Merge.sortMerge(jobs2, 64);
		Merge.sortMerge(jobs3, 256);	
		Merge.sortMerge(jobs4, 1024);
		Merge.sortMerge(jobs5, 4096);
		long time2=System.currentTimeMillis();
		
		
		
		BufferedWriter bw=new BufferedWriter(new FileWriter("data/a1_MergeSort_out.txt"));
		for(int i=0;i<jobs1.length;i++){
			bw.write(jobs1[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs2.length;i++){
			bw.write(jobs2[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs3.length;i++){
			bw.write(jobs3[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs4.length;i++){
			bw.write(jobs4[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		for(int i=0;i<jobs5.length;i++){
			bw.write(jobs5[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		
		
		System.out.println(time2-time1);
	}
	@Test
	public void testHeapSort() throws IOException{
		File file=new File("data/a1_in.txt");
		BufferedReader br=new BufferedReader(new FileReader(file));
		String[] content=new String[5];
		int n=0;
		String s0;
		while((s0=br.readLine()) != null){
			content[n]=s0;
			n++;
			//System.out.println(content);
		}
		Comparable[]jobs1=new Job[16];
		Comparable[]jobs2=new Job[64];
	Comparable[]jobs3=new Job[256];
		Comparable[]jobs4=new Job[1024];
		Comparable[]jobs5=new Job[4096];
		String[]s1=content[0].split(",");
		int idx=0;
		for(int i=0;i<s1.length;){
			String tmp1=s1[i].substring(1);
			i++;
			String tmp2=s1[i].substring(0, s1[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs1[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s2=content[1].split(",");
		idx=0;
		for(int i=0;i<s2.length;){
			String tmp1=s2[i].substring(1);
			i++;
			String tmp2=s2[i].substring(0, s2[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs2[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s3=content[2].split(",");
	 idx=0;
		for(int i=0;i<s3.length;){
			String tmp1=s3[i].substring(1);
			i++;
			String tmp2=s3[i].substring(0, s3[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs3[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s4=content[3].split(",");
	 idx=0;
		for(int i=0;i<s4.length;){
			String tmp1=s4[i].substring(1);
			i++;
			String tmp2=s4[i].substring(0, s4[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs4[idx]=new Job(id,seconds);
			idx++;
		}
		
		String[]s5=content[4].split(",");
		 idx=0;
		for(int i=0;i<s5.length;){
			String tmp1=s5[i].substring(1);
			i++;
			String tmp2=s5[i].substring(0, s5[i].length()-1);
			i++;
			String id=tmp1;
			int seconds=Integer.parseInt(tmp2);
			jobs5[idx]=new Job(id,seconds);
			//System.out.println(jobs5[idx]);
			idx++;
		}
		
		long time1=System.currentTimeMillis();
		Heap.sortHeap(jobs1, 16);
		Heap.sortHeap(jobs2, 64);
		Heap.sortHeap(jobs3, 256);
		Heap.sortHeap(jobs4, 1024);
		Heap.sortHeap(jobs5, 4096);
		long time2=System.currentTimeMillis();
		
		BufferedWriter bw=new BufferedWriter(new FileWriter("data/a1_HeapSort_out.txt"));
		for(int i=0;i<jobs1.length;i++){
			bw.write(jobs1[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs2.length;i++){
			bw.write(jobs2[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs3.length;i++){
			bw.write(jobs3[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		for(int i=0;i<jobs4.length;i++){
			bw.write(jobs4[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		for(int i=0;i<jobs5.length;i++){
			bw.write(jobs5[i].toString());
			bw.newLine();
		}
		bw.newLine();
		bw.newLine();
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		System.out.println(time2-time1);
	}
}
