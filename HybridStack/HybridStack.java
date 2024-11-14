public class HybridStack {
    HybridStackNode node = new HybridStackNode(4);
    public void makeEmpty(){
        node = new HybridStackNode(4);
    }

    public boolean isEmpty(){
        if (node.top == -1) {
            // If the current node is empty but there is a next node, check the next node
            if (node.next == null) {
                return true;  // Entire stack is empty
            } else {
                return node.next.isEmpty();  // Recursively check the next node
            }
        }
        return false;  // Current node is not empty
    }

    public void push(int x){
        node = node.push(x);
    }
    public int pop(){
        int removed_item=0;
        if(!node.isEmpty())
            removed_item = node.top();

        node= node.pop();
        return removed_item;
    }

    public int top(){
        if(!node.isEmpty())
            return node.top();
        return 0;
    }

    public void display(){
        System.out.println("Displaying:");
        HybridStackNode temp_node = node;
        while(temp_node.next!=null){
            temp_node.Display();
            temp_node = temp_node.next;
        }
        temp_node.Display();
        System.out.println();
    }
    public class HybridStackNode{
        int elements[];
        int top;
        int max;
        HybridStackNode next;
        public HybridStackNode(){
            elements = new int[5];
            top=-1;
            max =4;
        }
        public HybridStackNode(int n){
            elements = new int[n];
            top=-1;
            max =n;
        }
        public HybridStackNode push(int x){
            if(top+1<max){
                top++;
                elements[top]=x;
                return this;
            }
            else{
                HybridStackNode next_node = new HybridStackNode(max);
                next_node.push(x);
                next_node.next=this;
                return next_node;
            }
        }
        public HybridStackNode pop(){
            if(!isEmpty()){
                elements[top]=0;
                this.top--;
                if(top==-1){
                    if(next==null){
                        return new HybridStackNode(this.max);
                    }
                    return this.next;
                }
                return this;
            }
            else if(next!= null){
                next.pop();
                return next;
            }
            
            return new HybridStackNode(this.max);
        }
        public int top(){
            return elements[top];
        }
        public boolean isEmpty(){
            return top==-1;
        }
        public void Display(){
            for(int i=top;i>=0;i--)
                System.out.print(" "+elements[i]);
        }
    }
}