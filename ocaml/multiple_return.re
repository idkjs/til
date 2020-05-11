let three_four = (3, 4);
let five_six = (5, 6);

let () = {
  let (n1, n2) = three_four;
  Printf.printf("%d\n", n1);
  Printf.printf("%d\n", n2);
  /* if unuse */
  let (n3, _) = five_six;
  Printf.printf("%d\n", n3);
};
