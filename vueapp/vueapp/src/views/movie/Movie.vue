<template>
  <div class="loading">
    <div class="loading-content">
      <ul>
        <li class="clearfix" v-for="(item,index) in movieList" :key="index">
          <div class="loading-img">
            <img src="item.cover.url">
          </div>
          <div class="loading-info">
            <div>
              <h3>{{item.title}}</h3>
            </div>
            <span v-for="(item,index) in item.actors" :key="index">{{item}}/</span>
            <p>{{item.year}}年</p>
          </div>
        </li>
        <div class="mark" v-show="!isOver"></div>
      </ul>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      movieList: [],
      listStart: 0,
      res: [],
      isOver: true
    };
  },
  mounted() {
    window.onscroll = () => {
      let clientHeight = document.documentElement.clientHeight; //可视区域高度
      let scrollTop = document.documentElement.scrollTop; //滚动条所在高度
      let scrollHeight = document.documentElement.scrollHeight; //滚动条可滚动高度
      if (
        clientHeight + scrollTop >= scrollHeight - 10 &&
        this.movieList.lenght != this.res.data.total &&
        this.isOver
      ) {
        this.listStart += 10;
        this.getData();
      }
      console.log(this.res);
    };
  },
  created() {
    this.$emit("matchTab", "movie");
    this.getData();
  },
  methods: {
    getData() {
      let proxy = "https://bird.ioliu.cn/v2?url=";
      let url = `https://m.douban.com/rexxar/api/v2/subject_collection/movie_showing/items?start=${
        this.listStart
      }&count=10`;
      this.isOver = false;
      axios
        .get(proxy + url)
        .then(res => {
          this.movieList = this.movieList.concat(
            res.data.subject_collection_items
          );
          this.isOver = true;
          this.res = res;
          return this.res;
        })
        .catch(res => {
          console.log(this.movieList);
          console.log(0);
        });
    }
  }
};
</script>

<style>
.loading {
  margin-top: 1rem;
  margin-bottom: 1rem;
}
.loading-img {
  width: 40%;
}
.loading-img img {
  float: left;
  width: 80%;
  text-align: center;
}
.loading-info {
  width: 55%;
  float: left;
  padding-left: 5%;
}

.mark {
  position: fixed;
  top: 0;
  bottom: 0;
  left: 0;
  right: 0;
  background: rgba(0, 0, 0, 0.3);
}
</style>