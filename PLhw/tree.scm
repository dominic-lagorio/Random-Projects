(define (member? t x)
	(cond
	((null? t) #f)
	((< x (car t)) (member? (cadr t) x))
	((> x (car t)) (member? (caddr t) x))
	(else #t)))


(define (insert t x)
	(cond
		((null? t) (list x '() '()))
		((< x (car t)) (list (car t) (insert (cadr t) x) (caddr t)))
		((> x (car t)) (list (car t) (cadr t) (insert (caddr t) x)))
		(else t)))

(define (fold fun x lst)
	(if (null? lst) x (fold fun (fun x (car lst)) (cdr lst))))

(define (build lst)
	(fold (lambda (t v) (insert t v)) '() lst))
