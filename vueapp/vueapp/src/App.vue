<template>
  <div id="app">
    <CommonHeader :selectMenu="selectMenu"></CommonHeader>
    <router-view class="content" @matchTab="matchTab"/>
    <CommonFooter :footerbgc="selectMenu.bgc" :menuList="menuList"></CommonFooter>
  </div>
</template>

<script>
import CommonHeader from "@/components/CommonHeader.vue";
import CommonFooter from "@/components/CommonFooter.vue";
export default {
  components: {
    CommonHeader,
    CommonFooter
  },
  data() {
    return {
      selectMenu: {},
      menuList: [
        {
          title: "聊天",
          bgc: "rgb(63, 81, 181)",
          name: "talk",
          path: "/talk"
        },
        {
          title: "电影",
          bgc: "rgb(33, 150, 243)",
          name: "movie",
          path: "/movie"
        }
      ]
    };
  },
  methods: {
    matchTab(menuName) {
      this.menuList.forEach(menu => {
        if (menu.name == menuName) {
          this.selectMenu = menu;
        }
      });
    }
  }
};
</script>

