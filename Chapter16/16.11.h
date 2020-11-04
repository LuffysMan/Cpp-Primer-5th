template <typename elemType> class ListItem;        
template <typename elemType> class List {
public:
    List<elemType> ();
    List<elemType> (const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert (ListItem<elemType> *ptr, elemType value);      //在ListItem类外使用自身需要加上模板参数
private:
    ListItem<elemType> *front, *end;
};