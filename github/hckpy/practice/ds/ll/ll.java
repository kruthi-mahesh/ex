import java.io.*;
import java.util.*;
class ll{
	Node head;
	static class Node{
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
		if(cur1 == null){
			System.out.println("Not found");
			return;
		} 


		prev1.next = cur1.next;
	

	}
	ll create(){
		ll list = new ll();
		return list;
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		ll list = new ll();
		list.head = new Node(5);
		Node sec = new Node(6);
		Node third = new Node(7);
		list.head.next = sec;
		sec.next = third;
		list.print();
		list.add_last(10);
		list.print();
		list.add_beg(2);
		list.print();
		int item = list.del_first();
		if(item != -1)
			System.out.println("Successfully deleted " + item);
		list.print();
		item = list.del_last();
		if(item != -1)
			System.out.println("Successfully deleted " + item);
		list.print();
		list.add_last(12);
		list.print();
		list.del_first(2);
		list.del_first(12);
		list.del_first(5);
		list.print();
		list.add_last(6);
		list.add_last(6);
		list.del_last(6);
		list.print();
		/*while(1){
			ll l = new ll();
			System.out.println("Enter Choice\n-1.exit\n0.Print\n1.Create \n2.Add beginning\n3.Add last\n4.Add after n items\n5.delete beg\n6.del last\n7.del first occ of iten\n8.del last occ of item\n9.del item");
			int ch = in.nextInt();
			if(ch == -1){
				in.close();
				exit();
			}
			if(ch == 0)
				print(l);
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
				int index = in.nextInt();
				l.add_after(item,index);
			}
		}*/

	}
}