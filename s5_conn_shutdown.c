#include "s5_conn_shutdown.h"

bool h_shutdown(void* p, s5_epoll_t* ep) {
  s5_conn_t* c = p;
  int n1, n2;

  n1 = s5_buf_copy(c->buf, c->fd, c->peer->fd);
  if (n1 == -1) {
    return true;
  }

  n2 = s5_buf_copy(c->peer->buf, c->peer->fd, c->fd);
  if (n2 == -1) {
    return true;
  }

  return n1 == 0 && n2 == 0;
}
