let tail_recursion = n => {
  let rec iter = (i, n1, n2) =>
    if (i <= 0) {
      n2;
    } else if (i == 1) {
      n2;
    } else {
      iter(i - 1, n2, n1 + n2);
    };

  iter(n, 0, 1);
};

let () = {
  print_endline("tail_recursion");
  let start = Unix.gettimeofday();
  printf("%d\n", tail_recursion(100));
  printf("%.10f\n", Unix.gettimeofday() -. start);
};
