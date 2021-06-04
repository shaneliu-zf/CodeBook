template<class T>struct Node{
private:
public:
    int l_segment;
    int r_segment;
    Node<T> *l_son;
    Node<T> *r_son;
    T data;
    void setRange(int l,int r){l_segment=l,r_segment=r;}
    int getMid(){
        return (l_segment+r_segment)/2;
    }
};

template<class T>class SegmentTree{
private:
    Node<T> *root;
    vector<T> vec;
    function<T(T,T)>func;
    void build(Node<T> *now,int l,int r){
        now->setRange(l,r);
        if(l==r-1)now->data=vec[l];
        else{
            now->l_son=new Node<T>();
            now->r_son=new Node<T>();
            build(now->l_son,l,(l+r)/2);
            build(now->r_son,(l+r)/2,r);
            now->data=func(now->l_son->data,now->r_son->data);
        }
    }
    T query(Node<T> *now,int l,int r){
        if(now->l_segment==l && now->r_segment==r)return now->data;
        else{
            int mid=(now->l_segment+now->r_segment)/2;
            if(r<=mid)return query(now->l_son,l,r);
            else if(l>=mid)return query(now->r_son,l,r);
            else return func(query(now->l_son,l,mid),query(now->r_son,mid,r));
        }
    }
    void modify(Node<T> *now,int x,T value){
        if(now->l_segment==now->r_segment-1)now->data=value;
        else{
            int mid=(now->l_segment+now->r_segment)/2;
            if(x<mid)modify(now->l_son,x,value);
            else modify(now->r_son,x,value);
            now->data=func(now->l_son->data,now->r_son->data);
        }
    }
public:
    SegmentTree(vector<T>&_vec,function<T(T,T)>_func):vec(_vec),func(_func){
        root = new Node<T>();
        build(root,0,vec.size());
    }
    T query(int l,int r){return query(root,l,r);}
    void modify(int x,T value){modify(root,x,value);}
};
