<template>
  <div>
    <div class="talk-bar">
      <ul>
        <li></li>
      </ul>
    </div>
  </div>
</template>

<script>
export default {
  created() {
    this.$emit("matchTab", "talk");
  },
  methods: {
    getTimeStamp() {
      let timestamp = Date.parse(new Date()).toString.substr(0, 10);
      return timestamp;
    },
    getNonceStr(){
       let noncestr = Math.random().toString(36).substr(2);
       return noncestr;
    },
    getSign(){
        
    },
    send() {
      let params = {
        app_id: 2111975625,
        time_stamp:getTimeStamp(),
        nonce_str:getNonceStr(),
        session:10000,
        question:"空",
        sign
      };
    }
  }
};
</script>