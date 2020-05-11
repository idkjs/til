open Core;

class sample (param: string) = {
  as self;
  /* constructor, initialize params assign to instance variable */
  val mutable param = param;
  /* these `param` are instance variable (not initialize param) */
  pub get_param = param;
  pub set_param = s => param = s;
};

let () = {
  let sample1 = (new sample)("hogehoge");
  printf("%s\n", sample1#get_param);
  sample1#set_param("fuga");
  printf("%s\n", sample1#get_param);
};
