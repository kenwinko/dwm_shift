static void windowize(const Arg *arg);
static void shift_hor(const Arg *arg);
static void shift_ver(const Arg *arg);
static void update_old_coords(Client *c, int x, int y, int w, int h);

void
windowize(const Arg *arg) {
	Client *c = selmon->sel;

	int x = c->x;
	int y = c->y;

	int new_width = c->w * 0.5;
	int new_height = c->h * 0.5;

	resize(selmon->sel, x, y, new_width, new_height, 1);
	update_old_coords(c, x, y, new_width, new_height);
}

void
shift_hor(const Arg *arg) {
	Client *c = selmon->sel;

	int y = c->y;
	int x = c->x;
	int width = c->w;
	int height = c->h;

	int shift = x + arg->i * width * .25;

	resize(c, shift, y, width, height, 1);
	update_old_coords(c, shift, y, width, height);
}

void
shift_ver(const Arg *arg) {
	Client *c = selmon->sel;

	int y = c->y;
	int x = c->x;
	int width = c->w;
	int height = c->h;

	int shift = y + arg->i * height * .25;

	resize(c, x, shift, width, height, 1);
	update_old_coords(c, x, shift, width, height);
}

void
update_old_coords(Client *c, int x, int y, int w, int h) {
	c->x = x;
	c->y = y;
	c->w = w;
	c->h = h;
}
