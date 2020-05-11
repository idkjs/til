open Core;

let random = n => Random.int(n);

let () = {
  Random.self_init();
  for (i in 0 to 10) {
    Printf.printf("%d\n") @@ random(100);
    Unix.sleep(1);
    Out_channel.flush(stdout);
  };
};
