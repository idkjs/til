class progress_bar (x) = {
  as _;
  val mutable max_val = x;
  val mutable current_val = 0;
  pub update = x => current_val = x;
};
