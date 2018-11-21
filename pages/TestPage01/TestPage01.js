// pages/TestPage01/TestPage01.js

var QQMapWX = require('../../qqmap-wx-jssdk1/qqmap-wx-jssdk.js');
var qqmapDemo01;

Page({

  /**
   * 页面的初始数据
   */
  data: {
    myLatitude: "30.83391761779785", //纬度
    myLongitude: "121.50714111328125", //经度
    markers: [{
      iconPath: "/resources/others.png",
      id: 0,
      latitude:
        30.83391761779785,
      longitude: 121.50714111328125,
      width: 50,
      height: 50
    }],
    polyline: [{
      points: [{
        longitude: 121.50714111328125,
        latitude: 30.83391761779785
      }, {
          longitude: 121.50714111328125,
          latitude: 30.83391761779785
      }],
      color: "#FF0000DD",
      width: 2,
      dottedLine: true
    }],
    controls: [{
      id: 1,
      iconPath: '/resources/location.png',
      position: {
        left: 0,
        top: 300 - 50,
        width: 50,
        height: 50
      },
      clickable: true
    }]

  },
  //地图相关函数
  regionchange(e) {
    console.log(e.type)
  },
  markertap(e) {
    console.log(e.markerId)
  },
  controltap(e) {
    console.log(e.controlId)
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    // 实例化API核心类
    qqmapDemo01 = new QQMapWX({
      key: 'M3PBZ-4E7C3-HGL3O-YLQEB-DF4WS-OLBPS'
    });
    
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    // 调用接口:查询
    qqmapDemo01.search({
      keyword: 'kfc',
      success: function (res) {
        console.log(res);
      },
      fail: function (res) {
        console.log(res);
      },
      complete: function (res) {
        console.log(res);
      }
    });
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})