import Vue from "vue";
import Router from "vue-router";
import Talk from "@/views/talk/Talk.vue";
import Movie from "@/views/movie/Movie.vue";
import MovieDetails from "@/views/movie/MovieDetails";

Vue.use(Router);

export default new Router({
  mode: "history",
  base: process.env.BASE_URL,
  routes: [
    {
      path: "/",
      redirect: "/talk"
    },
    {
      path: "/talk",
      name: "talk",
      component: Talk
    },
    {
      path: "/movie",
      name: "movie",
      component: Movie
    },
    {
      path: "/music",
      name: "music",
      component:()=>import("@/views/music/Music.vue")
    },
    {
      path: "/moviedetails/:id",
      name: "moviedetails",
      component: () => import("@/views/movie/MovieDetails.vue")
    }
  ]
});

/* 
  笔记:
    url传参要有占位
    用chrildren传子组件要用routlink引用

*/
