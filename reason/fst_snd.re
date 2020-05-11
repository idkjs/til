let return_pair = (x, y) => (x, y);

let () = {
  let pair = return_pair(10, 5);
  Printf.printf("%d\n") @@ fst(pair);
  Printf.printf("%d\n") @@ snd(pair);
};
