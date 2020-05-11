open Core;

let random_int = ((n, m), x) => {
  let rec iter = (l, n') =>
    if (n' <= 0) {
      l;
    } else {
      iter([Random.int_incl(n, m), ...l], n' - 1);
    };
  iter([], x);
};

let () = {
  Random.self_init();
  let l = random_int((5, 10), 10);
  List.iter(l, ~f=e => printf("%d\n", e));
};
