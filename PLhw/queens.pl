can_place(_, []) :- !.
can_place(q(R,C), Board) :-
	member(q(Ra,Ca), Board), abs(Ra-R) =:= abs(Ca-C), !, fail.
can_place(_,_).

queens([], [], Board, Board).
queens([q(R)|Queens], Columns, Board, Solution) :-
	nth0(_, Columns, C, Free), can_place(q(R,C), Board),
	queens(Queens, Free,
