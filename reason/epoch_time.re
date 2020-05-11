open Core;

let () = {
  /* time function truncates float part */
  let _epoch = Unix.time();
  printf("%.10f\n", _epoch);
  /* epoch time */
  let start = Unix.gettimeofday();
  Unix.sleep(5);
  let end_ = Unix.gettimeofday();
  printf("%.10f\n", end_ -. start);
};
