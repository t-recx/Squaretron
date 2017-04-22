#include <allegro.h>

#define MAX_ENEMIES 50
#define MAX_CIVILIANS 50
#define MAX_WAVES 7
#define MAX_BULLETS 300

typedef struct
{
 int x, y;
 int active;
} ENEMY;

typedef struct
{
 int x, y;
 int active;
} CIV;

typedef struct
{
 int x, y;
 int active;
 int dx, dy;
} BULLET;

typedef struct
{
 int x, y;
 BULLET bullet[MAX_BULLETS];
} PLAYER;

typedef struct
{
 PLAYER player;
 ENEMY enemy[MAX_ENEMIES];
 CIV civilian[MAX_CIVILIANS];
} GAME;

typedef struct
{
 ENEMY enemy[MAX_ENEMIES];
 CIV civilian[MAX_CIVILIANS];
} WAVE;

WAVE wave[MAX_WAVES]=
{
 {
   {
    /* ENEMIES */
    /* x, y, active */
    { 10, 10, 1 },
    { 10, 230, 1 },
    { 310, 10, 1 },
    { 310, 230, 1 },
    { 20, 20, 1 },
    { 20, 220, 1 },
    { 300, 20, 1 },
    { 300, 220, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 120, 80, 1 },
    { 120, 160, 1 },
    { 200, 80, 1 },
    { 200, 160, 1 },
   }
 },
 {
  {
    /* ENEMIES */
    /* x, y, active */
    { 110, 60, 1 },
    { 70, 20, 1 },
    { 30, 210, 1 },
    { 240, 170, 1 },
    { 120, 80, 1 },
    { 20, 130, 1 },
    { 250, 120, 1 },
    { 300, 240, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 120, 80, 1 },
    { 200, 80, 1 },
   }
 },
 {
  {
    /* ENEMIES */
    /* x, y, active */
    { 210, 160, 1 },
    { 170, 220, 1 },
    { 130, 10, 1 },
    { 300, 70, 1 },
    { 10, 180, 1 },
    { 230, 30, 1 },
    { 20, 220, 1 },
    { 40, 40, 1 },
    { 250, 120, 1 },
    { 140, 240, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 100, 80, 1 },
    { 100, 160, 1 },
   }
 }, 
 {
  {
    /* ENEMIES */
    /* x, y, active */
    { 80, 50, 1 },
    { 60, 20, 1 },
    { 130, 210, 1 },
    { 300, 120, 1 },
    { 10, 40, 1 },
    { 230, 160, 1 },
    { 20, 20, 1 },
    { 40, 40, 1 },
    { 20, 120, 1 },
    { 140, 40, 1 },
    { 210, 140, 1 },
    { 310, 60, 1 },
    { 40, 120, 1 },
    { 20, 10, 1 },
    { 40, 140, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 10, 80, 1 },
    { 300, 210, 1 },
   }
 }, 
{
  {
    /* ENEMIES */
    /* x, y, active */
    { 90, 50, 1 },
    { 30, 220, 1 },
    { 30, 110, 1 },
    { 300, 150, 1 },
    { 10, 140, 1 },
    { 230, 60, 1 },
    { 20, 40, 1 },
    { 40, 60, 1 },
    { 20, 20, 1 },
    { 10, 40, 1 },
    { 210, 140, 1 },
    { 30, 60, 1 },
    { 40, 120, 1 },
    { 220, 10, 1 },
    { 310, 140, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 210, 90, 1 },
    { 30, 210, 1 },
    { 110, 140, 1 },
    { 70, 110, 1 },
    { 10, 80, 1 },
    { 60, 10, 1 },
   }
 }, 
{
  {
    /* ENEMIES */
    /* x, y, active */
    { 0, 20, 1 },
    { 0, 40, 1 },
    { 0, 60, 1 },
    { 0, 80, 1 },
    { 0, 100, 1 },
    { 0, 120, 1 },
    { 0, 140, 1 },
    { 0, 160, 1 },
    { 0, 180, 1 },
    { 320, 20, 1 },
    { 320, 40, 1 },
    { 320, 60, 1 },
    { 320, 80, 1 },
    { 320, 100, 1 },
    { 320, 120, 1 },
    { 320, 140, 1 },
    { 320, 160, 1 },
    { 320, 180, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 40, 40, 1 },
    { 40, 80, 1 },
    { 280, 160, 1 },
    { 260, 200, 1 },
   }
 },  
{
  {
    /* ENEMIES */
    /* x, y, active */
    { 0, 20, 1 },
    { 0, 40, 1 },
    { 0, 60, 1 },
    { 0, 80, 1 },
    { 0, 100, 1 },
    { 0, 120, 1 },
    { 0, 140, 1 },
    { 0, 160, 1 },
    { 0, 180, 1 },
    { 320, 20, 1 },
    { 320, 40, 1 },
    { 320, 60, 1 },
    { 320, 80, 1 },
    { 320, 100, 1 },
    { 320, 120, 1 },
    { 320, 140, 1 },
    { 320, 160, 1 },
    { 320, 180, 1 },
    { 20, 0, 1 },
    { 40, 0, 1 },
    { 80, 0, 1 },
    { 100, 0, 1 },
    { 120, 0, 1 },
    { 140, 0, 1 },
    { 160, 0, 1 },
    { 180, 0, 1 },
    { 200, 0, 1 },
    { 20, 220, 1 },
    { 40, 220, 1 },
    { 80, 220, 1 },
    { 100, 220, 1 },
    { 120, 220, 1 },
    { 140, 220, 1 },
    { 160, 220, 1 },
    { 180, 220, 1 },
    { 200, 220, 1 },
   },
   {
    /* CIVILIANS */
    /* x, y, active */
    { 40, 40, 1 },
    { 40, 80, 1 },
    { 280, 160, 1 },
    { 260, 200, 1 },
   }
 },  
 
};

volatile int counter= 0;

int seed;

int lives= 3, score= 0, cwave= 1;

SAMPLE *wav_bullet= NULL;
SAMPLE *wav_lose= NULL;
SAMPLE *wav_win= NULL;
SAMPLE *wav_blip= NULL;
SAMPLE *wav_music= NULL;
SAMPLE *wav_music2= NULL;

int bullet_voice= 2;

void counter_add ()
{
 counter++;
} END_OF_FUNCTION (counter_add);

int rr (int mi, int ma)
{
 return (rand ()%(ma+1 - mi)) + mi;
}

int rand_ex (int mi, int ma)
{
 seed++;
 return (rr (mi+seed, ma+seed)-seed);
}

GAME *init_game ()
{
 int c;
 GAME *game;
 
 game= malloc (sizeof (GAME));
 game->player.x= 320/2;
 game->player.y= 240/2;
 
 for (c=0;c<MAX_ENEMIES;c++)
 {
  game->enemy[c].x= 0;
  game->enemy[c].y= 0;
  game->enemy[c].active= 0;
 }
 
 for (c=0;c<MAX_CIVILIANS;c++)
 {
  game->civilian[c].x= 0;
  game->civilian[c].y= 0;
  game->civilian[c].active= 0;
 }
 
 for (c=0;c<MAX_BULLETS;c++)
 {
  game->player.bullet[c].x= 0;
  game->player.bullet[c].y= 0;
  game->player.bullet[c].dx= 0;
  game->player.bullet[c].dy= 0;
  game->player.bullet[c].active= 0;
 }
 
 return (game);
}

void destroy_game (GAME *game)
{
 free (game);
}

void draw_player (GAME *game, BITMAP *bmp)
{
 int rtm= text_mode (-1);
 rectfill (bmp, game->player.x, game->player.y, game->player.x+8, game->player.y+8, 255);
 textprintf (bmp, font, game->player.x+1, game->player.y+1, 16, "R");
 text_mode (rtm);
}

void draw_enemies (GAME *game, BITMAP *bmp)
{
 int rtm= text_mode (-1);
 int c;
 for (c=0;c<MAX_ENEMIES;c++)
 {
  if (game->enemy[c].active)
  {
   rectfill (bmp, game->enemy[c].x, game->enemy[c].y, game->enemy[c].x+8, game->enemy[c].y+8, 40);
   textprintf (bmp, font, game->enemy[c].x+1, game->enemy[c].y+1, 16, "E");
  }
 }
 text_mode (rtm);
}

void draw_civilians (GAME *game, BITMAP *bmp)
{
 int rtm= text_mode (-1);
 int c;
 for (c=0;c<MAX_CIVILIANS;c++)
 {
  if (game->civilian[c].active)
  {
   rectfill (bmp, game->civilian[c].x, game->civilian[c].y, game->civilian[c].x+8, game->civilian[c].y+8, 48);
   textprintf (bmp, font, game->civilian[c].x+1, game->civilian[c].y+1, 16, "H");
  }
 }
 text_mode (rtm);
}

void draw_bullets (GAME *game, BITMAP *bmp)
{
 int c;
 for (c=0;c<MAX_BULLETS;c++)
 {
   if (game->player.bullet[c].active)
   {
     putpixel (bmp, game->player.bullet[c].x, game->player.bullet[c].y, 44);
   }
 }
}

void draw_game (GAME *game, BITMAP *bmp)
{
 textprintf (bmp, font, 0, 0, 255, "Score: %d", score);
 textprintf_right (bmp, font, 320, 0, 255, "%d Lives", lives);
 textprintf_centre (bmp, font, 160, 0, 1, "Wave %d", cwave);
}

int fire_bullet (GAME *game, int dx, int dy)
{
 int c;
 for (c=0;c<MAX_BULLETS;c++)
 {
  if (!game->player.bullet[c].active)
  {
   game->player.bullet[c].x= game->player.x+4;
   game->player.bullet[c].y= game->player.y+4;
   game->player.bullet[c].dx= dx;
   game->player.bullet[c].dy= dy;
   game->player.bullet[c].active= 1;
   if (voice_check (bullet_voice)==NULL)
   {
    bullet_voice= play_sample (wav_bullet, 128, 128, 1000, 0); 
   }
   return (1);
  }
 }
 return (0);
}

void logic_player (GAME *game)
{
 int dx= 0, dy= 0;
 if (key[KEY_LEFT] && game->player.x>0)
 {
  game->player.x--;
 }
 if (key[KEY_RIGHT] && game->player.x<320-9)
 {
  game->player.x++;
 }
 if (key[KEY_UP] && game->player.y>10)
 {
  game->player.y--;
 }
 if (key[KEY_DOWN] && game->player.y<240-9)
 {
  game->player.y++;
 }
 if (key[KEY_A])
 {
  dx--;
 }
 if (key[KEY_D])
 {
  dx++;
 }
 if (key[KEY_W])
 {
  dy--;
 }
 if (key[KEY_S])
 {
  dy++;
 }
 if (dx || dy)
 {
  fire_bullet (game, dx, dy);
 }
}

int logic_enemies (GAME *game)
{
 int c, a= 0;
 for (c=0;c<MAX_ENEMIES;c++)
 {
   if (game->enemy[c].active)
   {
    a++;
    if (game->enemy[c].x>=game->player.x-8 && game->enemy[c].x<game->player.x+8)
    {
     if (game->enemy[c].y>=game->player.y-8 && game->enemy[c].y<game->player.y+8)
     {
      lives--;
      return (1);
     }
    }
    if (rand_ex (0, 1))
    {
     if (game->enemy[c].x<game->player.x)
     {
      game->enemy[c].x++;
     }
     if (game->enemy[c].x>game->player.x)
     {
      game->enemy[c].x--;
     }
     if (game->enemy[c].y<game->player.y)
     {
      game->enemy[c].y++;
     }
     if (game->enemy[c].y>game->player.y)
     {
      game->enemy[c].y--;
     }
    }
   }
 }
 if (a==0)
 {
  return (2);
 }
 return (0);
}

void logic_civilians (GAME *game)
{
 int c;
 for (c=0;c<MAX_CIVILIANS;c++)
 {
  if (game->civilian[c].active)
  {
   if (game->civilian[c].x>=game->player.x-8 && game->civilian[c].x<game->player.x+8)
   {
    if (game->civilian[c].y>=game->player.y-8 && game->civilian[c].y<game->player.y+8)
    {
     score+=100;
     play_sample (wav_blip, 128, 128, 1000, 0);
     game->civilian[c].active= 0;
    }
   }
   if (rand_ex (0, 1))
   {
     game->civilian[c].x+= rand_ex (-1, 1);
     game->civilian[c].y+= rand_ex (-1, 1);
     if (game->civilian[c].x<0) { game->civilian[c].x=0; }
     if (game->civilian[c].y<10) { game->civilian[c].y=10; }
     if (game->civilian[c].x>320) { game->civilian[c].x=320; }
     if (game->civilian[c].x>240) { game->civilian[c].x=240; }
   }
  }
 }
}

void logic_bullets (GAME *game)
{
 int c;
 for (c=0;c<MAX_BULLETS;c++)
 {
  if (game->player.bullet[c].active)
  {
   int e;
   game->player.bullet[c].x+= game->player.bullet[c].dx;
   game->player.bullet[c].y+= game->player.bullet[c].dy;
   if (game->player.bullet[c].x>320 || game->player.bullet[c].x<0)
   {
    game->player.bullet[c].active= 0;
   }
   if (game->player.bullet[c].y>240 || game->player.bullet[c].y<0)
   {
    game->player.bullet[c].active= 0;
   }
   for (e=0;e<MAX_ENEMIES;e++)
   {
    if (game->enemy[e].active)
    {
     if (game->player.bullet[c].x>=game->enemy[e].x && game->player.bullet[c].x<game->enemy[e].x+8)
     {
      if (game->player.bullet[c].y>=game->enemy[e].y && game->player.bullet[c].y<game->enemy[e].y+8)
      {
       game->player.bullet[c].active= 0;
       game->enemy[e].active= 0;
       score+=100;
      }
     }
    }
   }
  }
 }
}

void logic_game (GAME *game)
{
 if (key[KEY_ESC])
 {
  destroy_game (game);
  allegro_exit ();
  exit (0);
 }
}

void add_wave_to_game (WAVE *wave, GAME *game)
{
 int c;
 for (c=0;c<MAX_ENEMIES;c++)
 {
   game->enemy[c].x= wave->enemy[c].x;
   game->enemy[c].y= wave->enemy[c].y;
   game->enemy[c].active= wave->enemy[c].active;
 }
 for (c=0;c<MAX_CIVILIANS;c++)
 {
   game->civilian[c].x= wave->civilian[c].x;
   game->civilian[c].y= wave->civilian[c].y;
   game->civilian[c].active= wave->civilian[c].active;
 }
}

int start_game (WAVE *wave)
{
 BITMAP *swap= NULL;
 GAME *game= NULL;
 
 game= init_game ();
 counter= 0;
 add_wave_to_game (wave, game);
 
 swap= create_bitmap (320, 240);
 clear (swap);
 //play_sample (wav_music, 16, 128, 1000, 1);
 while (1)
 {
  while (counter>0)
  {
    int le;
    poll_keyboard ();
    logic_game (game);
    logic_player (game);
    logic_bullets (game);
    le= logic_enemies (game);
    if (le==1)
    {
     stop_sample (wav_music);
     destroy_game (game);
     destroy_bitmap (swap);
     return (1);
    }
    else if (le==2)
    {
     stop_sample (wav_music);
     destroy_game (game);
     destroy_bitmap (swap);
     return (2);
    }
    logic_civilians (game);
    counter--;
  }
  draw_enemies (game, swap);
  draw_civilians (game, swap);
  draw_bullets (game, swap);
  draw_player (game, swap);
  draw_game (game, swap);
  blit (swap, screen, 0, 0, 0, 0, 320, 240);
  vsync ();
  clear (swap);
 }
 
 stop_sample (wav_music);
 destroy_game (game);
 destroy_bitmap (swap);
 return (0);
} 

void start ()
{
 int w;
 int mvoice;
 int bps= 60;
 BITMAP *logo= create_bitmap (10*8, 8);
 
 clear (logo);
  
 LOCK_VARIABLE (counter);
 LOCK_FUNCTION (counter_add);
 install_int_ex (counter_add, BPS_TO_TIMER (60));
 
 wav_bullet= load_sample ("wav/shot.wav");
 wav_lose= load_sample ("wav/lose.wav");
 wav_win= load_sample ("wav/win.wav");
 wav_blip= load_sample ("wav/blip.wav");
 wav_music= load_sample ("wav/gamemusic1.wav");
 wav_music2= load_sample ("wav/gamemusic2.wav");
 
 textprintf (logo, font, 0, 0, 255, "SQUARETRON");
 
 
 
 start:
 score= 0;
 lives= 3;
 bps= 60;
 cwave= 1;
 install_int_ex (counter_add, BPS_TO_TIMER (60));
 srand (time (NULL));
 clear (screen);
 stretch_sprite (screen, logo, 0, 0, 320, 80);
 
 textprintf (screen, font, 0, 240-8, 255, "High Score: %d", get_config_int ("Score", "Last", 1000));

 
 textprintf_centre (screen, font, 160, 160, 255, "Press a key to play SQUARETRON!");

 textprintf (screen, font, 0, 180, 40, "A, S, W, D");
 textprintf_right (screen, font, 320, 180, 48, "Left, Right, Up, Down");

 
 mvoice= play_sample (wav_music, 128, 128, 1000, 1);
 readkey ();
 stop_sample (wav_music);
 
 restart_wave:
 for (w=0;w<MAX_WAVES;w++)
 {
  int sg;
  restart:
  sg= start_game (&wave[w]);
  if (sg==1)
  {
   play_sample (wav_lose, 128, 128, 1000, 0);
   alert ("", "You lost a life!", "", "OH NOES", NULL, 0, 0);
   if (!lives)
   {
    play_sample (wav_music2, 128, 128, 1000, 1);
    alert ("", "GAME OVER", "", "SUXXOR", NULL, 0, 0);
    stop_sample (wav_music2);
    if (score>get_config_int ("Score", "Last", 1000))
   {
     set_config_int ("Score", "Last", score);
    }
    goto start;
    allegro_exit ();
    exit (0);
   }
   goto restart;
  }
  play_sample (wav_win, 128, 128, 1000, 0);
  cwave++;
 }
 bps+= 10;
 install_int_ex (counter_add, BPS_TO_TIMER (bps));
 goto restart_wave;
 if (score>get_config_int ("Score", "Last", 1000))
 {
  set_config_int ("Score", "Last", score);
 }
 allegro_exit ();
 exit (1);
}

int main ()
{
 if (!allegro_init ()) if (!install_sound (DIGI_AUTODETECT, MIDI_AUTODETECT, NULL)) if (!install_keyboard ()) if (!install_timer ()) if (!set_gfx_mode (GFX_AUTODETECT, 320, 240, 0, 0)) start ();
 
 allegro_message ("Error: %s\n", allegro_error);
 allegro_exit ();

 return (0);
}
END_OF_MAIN ();