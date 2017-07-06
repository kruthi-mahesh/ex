import java.io.*;
import java.util.*;
class LL{

	Node head;
	class Node{
		int data;
		Node next;
		Node(int data){
			this.data = data;
		}

	}
	void print(){
		if(head == null){
			System.out.println("Empty list");
			return;
		}

		Node t = head;
		System.out.println("Current list is: ");
		while(t!=null){
			System.out.println(t.data);
			t = t.next;
		}
	}
	void add_last(int data){
		Node t =head;
		if(head == null){
			head = new Node(data);
			return;
		}
		while(t.next !=null)
			t= t.next;
		t.next = new Node(data);

	}
	void add_beg(int data){
		if(head == null){
			head = new Node(data);
			return;
		}
		Node t = new Node(data);
		t.next = head;
		head = t;

	}
	void add_after(int item,int index){
		if(head == null){
			head = new Node(item);
			return;
		}
		Node t= head;
		for(int i=0;t != null && i<index;i++)
			t = t.next;
		if(t == null || index <0){
			System.out.println("Invalid index");
			return;
		}
		Node newNode = new Node(item);
		newNode.next = t.next;
		t.next = newNode;
		
	}
	int del_first(){
		if(head == null){
			System.out.println("Empty list");
			return -1;
		}
		int t = head.data;
		head = head.next;
		return t;

	}
	int del_last(){
		if(head == null){
			System.out.println("Empty list");
			return -1;
		}
		if(head.next == null){
			int t = head.data;
			head = null;
			return t;
		}
		Node cur = head;
		Node prev = null;
		while(cur.next != null){
			
			prev = cur;
			cur = cur.next;
			
		}
		//delete currrent
		prev.next = cur.next;
		int t = cur.data;
		return t;


	}
	void del_first(int data){
		Node cur = head;
		Node pre = null;
		if(head == null){
			System.out.println("Cant delete from Empty list");
			return;
		}
	
		if(head.data == data){
			head = head.next;
			return;
		}
		while(cur != null && cur.data != data){
			pre = cur;
			cur = cur.next;
		}
		if(cur == null){
			System.out.println("Not found");
			return;
		} 

		if(cur.data == data)
			pre.next = cur.next;
	
	}
	void del_last(int data){
	
		Node cur = head;
		Node prev = null;
		Node cur1 = cur;
		Node prev1 = null;
		if(head == null){
			System.out.println("Cant delete from Empty list");
			return;
		}
		if(head.data == data){
			head = head.next;
			return;
		}
		while(cur != null){
			if(cur.data == data){
				cur1 = cur;
				prev1 = prev;
			}
			prev = cur;
			cur = cur.next;
		}
		if(cur1 == null || prev1 == null){
			System.out.println("Not found");
			return;
		} 

		if(cur1.data == data)
			prev1.next = cur1.next;
	

	}
	void del(int index){
		if(head == null){
			System.out.println("Cant del from empty list");
			return;
		}
		if(index == 0){
			head = head.next;
			return;
		}
		Node cur = head;
		Node pre = null;
		int i;
		for(i=0;cur!= null && i<index;i++){
			pre = cur;
			cur = cur.next;

		}
		if(i == index && cur!=null){
 			pre.next = cur.next;
 			return;
		}
		System.out.println("Invalid index");


	}
	static LL create(){
		LL list = new LL();
		return list;
	}
	void clearAll(){
		head = null;
	}
	int length(){
		Node t = head;
		int ct =0;
		while(t!=null){
			ct++;
			t = t.next;
		}
		return ct;
	}
	int length(Node head){
		if(head == null)
			return 0;
		else
			return 1 + length(head.next);
	}
	int length_rec(){
		return length(head);
	}
	void swap(int d1,int d2){
		if(d1 == d2){
			System.out.println("Cant be identical");
			return;
		}
		if(head == null || head.next == null){
			System.out.println("Not enough elements");
			return;
		}
		Node pre_x = null,cur_x=head,pre_y=null,cur_y=head;
		while(cur_x != null && cur_x.data != d1){
			pre_x =cur_x;
			cur_x = cur_x.next;
		}
		while(cur_y != null && cur_y.data != d2){
			pre_y = cur_y;
			cur_y=cur_y.next;
		}
		if(cur_x==null || cur_y == null){
			System.out.println("Not found");
			return;
		}
		if(pre_x == null)
			head = cur_y;
		else
			pre_x.next = cur_y;
		if(pre_y == null)
			head = cur_x;
		else
			pre_y.next = cur_x;
		Node temp = cur_x.next;
		cur_x.next = cur_y.next;
		cur_y.next = temp;
		
	}
	void swap_optimum(int d1,int d2){
		if(d1 == d2){
			System.out.println("Cant be identical");
			return;
		}
		if(head == null || head.next == null){
			System.out.println("Not enough elements");
			return;
		}
		Node cur =head,pre = null;
		Node pre_x = null,cur_x=head,pre_y=null,cur_y=head;		
		int ct=0;
		while(cur!=null){
			if(cur.data == d1){
				cur_x = cur;
				pre_x = pre;
				ct++;
				if(ct == 2)
					break;

			}
			else if(cur.data == d2){
				cur_y = cur;
				pre_y = pre;
				ct++;
				if(ct == 2)
					break;
			}
			pre = cur;
			cur= cur.next;
		}
		if(cur == null){
			System.out.println("Not found");
			return;
		}
		if(pre_x == null)
			head = cur_y;
		else
			pre_x.next = cur_y;
		if(pre_y == null)
			head = cur_x;
		else
			pre_y.next = cur_x;
		Node temp = cur_x.next;
		cur_x.next = cur_y.next;
		cur_y.next = temp;
		
	}
	void rev_rec(Node cur,Node prev) {
		if(cur == null){
			head = prev;
			return;
		}
		
		
		Node temp = cur.next;
		cur.next = prev;
		rev_rec(temp,cur);
		
	}
	
	void rev(){
		if(head == null){
			System.out.println("Empty list");
			return;
		}
		
		Node cur = head;
		Node pre = null;
		Node temp;
		while(cur != null ){
			temp = cur.next;
			cur.next = pre;
			pre = cur;
			cur = temp;

		}
		
		head = pre;
	}
	/*void rev_help(Node head){
		Node first,rest;
		if(head == null)
			return;
		first = head;
		rest = first.next;
		if(rest == null)
			return;
		rev_help(rest);
		first.next.next = first;
		first.next = null;
		head = rest;
	}

	void rev_rec(){
		rev_help(head);
	}
	*/
	void print_rev(Node head){
		if(head == null)
			return;
		print_rev(head.next);
		System.out.println(head.data);
	}
	void print_rev(){
		print_rev(head);
	}
	boolean search(Node head,int data){
		if(head == null)
			return false;
		if(head.data == data)
			return true;
		return search(head.next,data);
	}
	int get_n(int index){
		Node t = head;
		int ct=0;
		while(t!=null){
			if(ct == index)
				return t.data;
			ct ++;
			t = t.next;
		}
		return -1;
	}
	/*void get_n_rec(Node head,int index,Integer i){
		
		if(head == null )
			return;
		get_n_rec(head.next,index,i);
		if(++i == index)
			System.out.println(head.data);

	
	void get_n_rec(int index){
		 get_n_rec(head,index,0);
	}*/
	void get_n_rev(int index){
		if(head == null)
			return;
		Node fast,late;
		int ct=0;
		fast = head;
		late = head;
		while(ct <index){
			if(fast == null)
				return;
			ct++;
			fast = fast.next;
		}
	
		while(fast != null){
			fast = fast.next;
			late = late.next;
		}
		System.out.println(late.data);
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int item,index;
		LL l = new LL();
		while(1!=0){
			
			System.out.println("Enter Choice\n-1.exit\n0.Print\n1.Create \n2.Add beginning\n3.Add last\n4.Add after n items\n5.delete beg\n6.del last\n7.del first occ of item\n8.del last occ of item\n9.Delete at position index\n10.ClearAll\n11.Find length\n12.Find count recursively\n13. Swap 2 nodes with data d1 and d2 where d1!=d2 \n14.swap_optimum (same as 13)\n15.Reverse list\n16.Recursive reverse\n17.print rev\n18. search item\n19.print nth item\n20.Print nth item from end ");
			int ch = in.nextInt();
			if(ch == -1){
				in.close();
				break;
			}
			if(ch == 0)
				l.print();
			else if(ch == 1)
				l = create();
			else if(ch == 2){
				item=in.nextInt();
				l.add_beg(item);
			}
			else if(ch == 3){
				item=in.nextInt();
				l.add_last(item);
			}
			else if(ch == 4){
				item=in.nextInt();
				 index = in.nextInt();
				l.add_after(item,index);
			}
			else if(ch == 5){
				l.del_first();
			}
			else if(ch == 6)
				l.del_last();
			else if(ch == 7){
				item = in.nextInt();
				l.del_first(item);
			}
			else if(ch == 8){
				item = in.nextInt();
				l.del_last(item);
			}
			else if(ch == 9){
				index = in.nextInt();
				l.del(index);
			}
			else if(ch == 10){
				l.clearAll();
			}
			else if(ch == 11)
				System.out.println( l.length());
			else if(ch == 12)
				System.out.println( l.length_rec());
			else if(ch == 13){
				int d1 = in.nextInt();
				int d2 = in.nextInt();
				l.swap(d1,d2);
			}
			else if(ch == 14){
				int d1 = in.nextInt();
				int d2 = in.nextInt();
				l.swap_optimum(d1,d2);
			}
			else if(ch == 15)
				l.rev();
			else if(ch == 16)
				l.rev_rec(l.head,null);
			else if(ch == 17)
				l.print_rev();
			else if(ch == 18){
				item = in.nextInt();
				System.out.println(l.search(l.head,item));
			}
			else if(ch == 19){
				index = in.nextInt();
				System.out.println(l.get_n(index));
			}
			else if(ch == 20){
				index = in.nextInt();
				l.get_n_rev(index+1);
			}
		}

	}
}
