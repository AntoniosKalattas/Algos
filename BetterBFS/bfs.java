public static void bfs(int g[][], int in, int s, int size, SimpleQueue q){
        // in ::: keeps track who many numbers left to pop in order to get rid of the previous graph line.
        while(!q.isEmpty()){
            int pop = q.dequeue();
            in--;
            for(int i=0;i<size;i++)
                if(g[pop][i]==1){
                    q.enqueue(i);
                }
            if(in<=0){
                in=q.size;
                for(int i=0;i<in;i++){
                    int a = q.dequeue();
                    System.out.print(a+" ");
                    q.enqueue(a);
                }
            }

        }
    }
