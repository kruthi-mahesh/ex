/*Detect a loop in ll: http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/*/
	import java.util.*;
	class Ll{
		Node head;
		class Node{
			int data;
			Node next;
			Node(int data){
				this.data =data;
			}
		}
		void push(int data){
			Node newNode = new Node(data);
			if(head == null){
				head = newNode;
				return;
			}
			Node t = head;
			while(t.next != null)
				t=  t.next;
			t.next= newNode;
		}
		void print(){
			Node t = head;
			while(t !=null){
				System.out.println(t.data);
				t = t.next;
			}
		}
		void del(int item){
			if(head.data == item){
				head = head.next;
			}
			Node t = head;
			Node pre = null;
			while(t != null && t.data != item){
				pre = t;
				t = t.next;
			}
			if(t == null){
				System.out.println("Not found");
				return;
			}
			pre.next = t.next;
		}
		void insert(int item){
			if(head == null)
				return;
			Node cur = head;
			Node find = null;
			if(head.data == item){
				find = head;
			}
		
			while(cur.next != null){
				if(cur.next.data == item)
					find = cur.next;
				cur = cur.next;
			}
			if(find == null){
				System.out.println("Not found");
				return;
			}
			cur.next = find;
		}
		boolean detect_loop(){
			HashSet<Node> map = new HashSet<Node>();
			Node t = head;
			if(head == null)
				return false;
			if(head!=null){
				map.add(head);
				
			}
			while(t.next!=null){
			
				if(map.contains(t.next) == true)
					return true;
				map.add(t.next);
				t = t.next;
				
			}
			return false;
		}
		boolean detect(){
			if(head == null)
				return false;
			Node slow = head;
			Node fast= head.next;
			while(fast != null &&  fast.next != null){
				if(fast == slow)
					return true;
				slow = slow.next;
				fast = fast.next.next;
			}
			return false;
		}
		boolean del_loop_hash(){
			if(head == null)
				return false;
			HashSet<Node> map = new HashSet<Node>();
			Node t = head;
			if(head!=null){
				map.add(head);
				
			}
			while(t.next!=null){
			
				if(map.contains(t.next) == true){
					t.next = null;
					return true;
				}
				map.add(t.next);
				t = t.next;
				
			}
			return false;
		}
		boolean del_floyd(){
			if(head == null)
				return false;
			Node slow = head;
        	Node fast = head.next;
 
        // Search for loop using slow and fast pointers
       		while (fast != null && fast.next != null) {
            	if (slow == fast) {
                	break;
            	}
            	slow = slow.next;
            	fast = fast.next.next;
        	}
 
        /* If loop exists */
        	if (slow == fast) {
           		 slow = head;
            	while (slow != fast.next) {
                	slow = slow.next;
                	fast = fast.next;
            	}
 
            	/* since fast->next is the looping point */
            	fast.next = null; /* remove loop */
            	return true;
        	}
        	return false;
		}
		void push(Node newNode){
			if(head == null){
				head = newNode;
				head.next =null;
				return;				
			}
			Node cur = head;
			while(cur.next != null)
				cur = cur.next;
			cur.next = newNode;
			newNode.next = null;
		}
		void append(Node newNode){
			if(head == null){
				head= newNode;
				return;
			}
			Node cur = head;
			while(cur.next != null)
				cur = cur.next;
			cur.next = newNode;
		}
		public static Ll merge(Ll l1,Ll l2){
			Node cur1 = l1.head;
			Node cur2 = l2.head;
			Node temp;
			Ll res = new Ll();
			while(cur1 != null && cur2 != null){
				if(cur1.data <= cur2.data){
					temp = cur1.next;
					res.push(cur1);
					cur1 = temp;
				}
				else if(cur2.data<cur1.data){					
					temp = cur2.next;
					res.push(cur2);
					cur2 = temp;
				}

			}

			if(cur1 == null && cur2!=null)
				res.append(cur2);
			else if(cur2 == null && cur1!=null)
				res.append(cur1);

			return res;
		}
		static Node merge_rec(Node a,Node b){
			if(a == null)
				return b;
			if(b == null)
				return a;
			if(a.data <= b.data){
				
				a.next = merge_rec(a.next,b);
				return a;
			}
			else {
			
				b.next = merge_rec(a,b.next);
				return b;
			}
			
		}
		void insert_sorted(int item){
			Node cur = head;
			Node newNode = new Node(item);
			if(head == null || head.data >= item){
				newNode.next = head;
				head =newNode;
				return;
			}
			while(cur.next != null && cur.next.data<item)
				cur = cur.next;
			newNode.next = cur.next;
			cur.next = newNode;
		}
		void delNode(int item){
			if(head == null)
				return;
			if(head.data == item){
				head = delNode(head);
				return;
			}
			Node cur = head;
			while(cur.next != null){
				if(cur.next.data == item ){
					cur.next = delNode(cur.next);
					return;
				}
				cur = cur.next;
			}
			
		
		}
		static Node delNode(Node n){
			if(n.next == null)
				return null;
			n.data = n.next.data;
			n.next = n.next.next;
			return n;
	
		}
		public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			Ll l = new Ll();
			int item,index;
			while(1 != 0){
				System.out.println("\n\t0.print\n\t1.push\n\t2.del item\n\t3.create loop\n\t4.\tdetect loop\n\t5.detect and del loop\n\t6 repeat 5 using floyd\n\t7.merge list,my answer also at http://ide.geeksforgeeks.org/JHsfh4\n\t8.Merge recursively\n\t9.Insert item in sorted list\n\t10.delNode");
				System.out.print("Enter choice: \t");
				int ch = in.nextInt();
				switch(ch){
					case 0: l.print();	break;
					case 1:{ 
						item = in.nextInt();
						l.push(item);
						break;
					}
					case 2:{
						item =in.nextInt();
						l.del(item);
						break;
					}
					case 3:{
						item = in.nextInt();
						l.insert(item);

					}
					case 4:{
						System.out.println("Using hash: "+ l.detect_loop() + " Using floyd algo: "+ l.detect());
						break;
					}
					case 5:{
						System.out.println("Using hash: "+ l.del_loop_hash() );
						break;				
					}
					case 6:{
						System.out.println(" Using floyd algo: "+ l.del_floyd()+"\nRead this link to understand how:\nhttp://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/");

						break;
					}
					case 7:{
						System.out.println("Enter first list length");
						int n = in.nextInt();
						Ll l1 = new Ll();
						for(int i =0 ;i<n;i++)
							l1.push(in.nextInt());
						System.out.println("Enter sec list length");
						n = in.nextInt();
						Ll l2 = new Ll();
						for(int i =0 ;i<n;i++)
							l2.push(in.nextInt());
						l1 = merge(l1,l2);
						System.out.println("After merging 2 lists,new list is :");
						l1.print();
						break;
					}
					case 8:{
						System.out.println("Enter first list length");
						int n = in.nextInt();
						Ll l1 = new Ll();
						for(int i =0 ;i<n;i++)
							l1.push(in.nextInt());
						System.out.println("Enter sec list length");
						n = in.nextInt();
						Ll l2 = new Ll();
						for(int i =0 ;i<n;i++)
							l2.push(in.nextInt());
						l1.head = merge_rec(l1.head,l2.head);
						System.out.println("After merging 2 lists,new list is :");
						l1.print();
						break;
					}
					case 9:{
						item=in.nextInt();
						l.insert_sorted(item);
						System.out.println("New list");
						l.print();
						break;
					}	
					case 10:{
						item=in.nextInt();
						l.delNode(item);
						l.print();
						break;
					}	
				}
			}
		}
 	}
