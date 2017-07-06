import java.util.*;
class palindrome{
	Node head;
	Node second_half;
	Node middle_node = null;
	Node pre,left;
	class Node{
		int data;
		Node next;
		Node(int item){
			data = item;
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
	void push(int data){
		Node t =head;
		if(head == null){
			head = new Node(data);
			return;
		}
		while(t.next !=null)
			t= t.next;
		t.next = new Node(data);

	}
	void del(int data){
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
	void rev(){
		
		if(second_half == null)
			return;
		Node pre = null;
		Node cur = second_half;
		
		while(cur != null){
			Node next = cur.next;
			cur.next = pre;
			pre = cur;
			cur = next;
		}
		second_half = pre;
	}
	boolean compare(Node l1,Node l2){
		
		Node cur1 = l1;
		Node cur2 = l2;
		while(cur2 != null){
			if(cur1.data != cur2.data)
				return false;
			cur1 = cur1.next;
			cur2 = cur2.next;
		}
		return true;
	}
	boolean isPal(){
		if(head == null)
			return true;
		if(head.next == null)
			return true;
		Node slow = head;
		Node fast = head;
		Node pre = null;
		while(fast != null && fast.next != null){
			pre = slow;
			fast = fast.next.next;
			slow = slow.next;
		}
		if(fast != null){
			middle_node = slow;
			slow = slow.next;
		}
		second_half = slow;
		rev();
		boolean res = compare(head,second_half);
		rev();
		if(middle_node != null){
			pre.next = middle_node;
			middle_node.next = second_half;
			return res;
		}
		pre.next = second_half;
		return res;
	}
	boolean isPal(Node right) 
    {
        left = head;
         
        /* stop recursion when right becomes NULL */
        if (right == null)
            return true;
 
        /* If sub-list is not palindrome then no need to
           check for current left and right, return false */
       
        if(isPal(right.next) == false)
        	return false;
        
        /* Check values at current left and right */
        boolean isp = (right.data == (left).data);
 
        /* Move left to next node */
        left = left.next;
 
        return isp;
    }
 
		boolean isPal_stack(){
			Stack<Integer> st = new Stack<Integer>();
			Node cur = head;
			while(cur != null){
				st.push(cur.data);
				cur = cur.next;
			}
			cur = head;
			while(cur != null){
				if(cur.data != st.pop())
					return false;
				cur = cur.next;
			}
			return true;
		}
		public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			palindrome l = new palindrome();
			int item,index;
			while(1 != 0){
				System.out.println("\n\t0.print\n\t1.push\n\t2.del item\n\t3.isPal: O(1) space\n\t4.isPal using stack : O(n) extra space\n\t5.is pal using recursion");
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
						System.out.println(l.isPal());
						break;
					}
					case 4:{
						System.out.println(l.isPal_stack());
						break;
					}
					case 5:{
						System.out.println(l.isPal(l.head));
						break;
					}
				}
			}
		}



}