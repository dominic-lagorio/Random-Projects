datatype tree = NULL | node of (int * tree * tree);

fun member NULL x = false
	| member (node(d, l, r)) x = 
		if d = x then
			true
		else if x < d then 
			member l x 
		else 
			member r x;

fun insert NULL x = node (x, NULL, NULL)
	| insert (node(d, l, r)) x = 
		if d = x then
			node (d, l, r)
		else if d < x then
			node(d, l, insert r x)
		else
			node(d, insert l x, r);

val build = foldl (fn(v, t) => insert t v) NULL;

fun inorder NULL = []
	| inorder (node(d, l, r)) = inorder l @ d :: inorder r;  
