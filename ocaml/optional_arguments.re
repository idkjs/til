/* like List.init */
let gen = (~start=0, end_) => {
  let rec iter = (n, list_: list(int)) =>
    if (n > end_) {
      List.rev(list_);
    } else if (start >= end_) {
      [];
    } else {
      iter(n + 1, [n, ...list_]);
    };

  iter(start, []);
};

let () = {
  List.iter(e => Printf.printf("%d ", e), gen(~start=?Some(3), 10));
  print_string("\n\n");
  List.iter(e => Printf.printf("%d ", e), gen(~start=3, 10));
  print_string("\n\n");
  List.iter(e => Printf.printf("%d ", e), gen(10));
};
