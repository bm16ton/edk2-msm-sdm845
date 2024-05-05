let last_bytes=0,last_frames=0;
let mod={
	get_fps:null,
	get_bytes:null,
	start:null,
	disconnect:null,
	refresh:null,
	set_paused:null,
	initialize:null,
};
function getWebSocket(){
	const proto=document.location.protocol==="https:"?"wss:":"ws:";
	return proto+"//"+document.location.host+"/websocket";
}
Math.roundX=function(value,length=0){
	if(Math.round(length)!==length)throw "Not a integer";
	if(length>10)throw "Number to big";
	if(length<1)return Math.round(value);
	length=Math.pow(10,length);
	return Math.round(value*length)/length;
}
function format_size(size,level=-1,length=2){
	const units=["B","KB","MB","GB","TB","PB","EB","ZB","YB","BB","NB","DB","CB"];
	const unit=Math.min(units.length+1,Math.floor(Math.log(size)/Math.log(2)/10));
	const prec=3;
	size=Math.round(Math.abs(size));
	if(size===0)return "0"+units[0];
	if(level>units.length)throw "Level too big";
	if(level!==-1)return Math.roundX(size/Math.max(Math.pow(1024,level),1),length)+units[unit];
	size=size*Math.pow(2,-10*unit);
	const digi=prec-1-Math.floor(Math.log(size)/Math.log(10));
	size=Math.round(size*Math.pow(10,digi))*Math.pow(10,-digi);
	return Math.roundX(size,length)+units[unit];
}
function counter(){
	const fps=document.querySelector("span#fps");
	const speed=document.querySelector("span#speed");
	const trans=document.querySelector("span#trans");
	if(mod.get_bytes){
		const bytes=mod.get_bytes();
		const frames=mod.get_frames();
		if(last_frames!==0){
			const got=frames-last_frames;
			if(fps)fps.innerText=got;
		}
		if(last_bytes!==0){
			const got=bytes-last_bytes;
			if(speed)speed.innerText=format_size(got)+"/s";
		}
		if(trans)trans.innerText=format_size(bytes);
		last_frames=frames;
		last_bytes=bytes;
	}
	setTimeout(counter,1000);
}
function load_functions(){
	mod.refresh=Module.cwrap("web_gui_refresh",null,[]);
	mod.initialize=Module.cwrap("web_gui_initialize",null,[]);
	mod.disconnect=Module.cwrap("web_gui_disconnect",null,[]);
	mod.start=Module.cwrap("web_gui_start","number",["string"]);
	mod.get_bytes=Module.cwrap("web_gui_get_bytes","number",[]);
	mod.get_frames=Module.cwrap("web_gui_get_frames","number",[]);
	mod.set_paused=Module.cwrap("web_gui_set_paused",null,["boolean"]);
	mod.set_compressed=Module.cwrap("web_gui_set_compressed",null,["boolean"]);
}
window.addEventListener("load",()=>{
	const compressed=document.querySelector("input#compressed");
	const reconnect=document.querySelector("button#reconnect");
	const disconnect=document.querySelector("button#disconnect");
	const refresh=document.querySelector("button#refresh");
	const resume=document.querySelector("button#resume");
	const pause=document.querySelector("button#pause");
	Module.canvas=document.querySelector("canvas#canvas");
	Module.onRuntimeInitialized=()=>{
		load_functions();
		mod.initialize();
		mod.start(getWebSocket());
		compressed.addEventListener("change",()=>mod.set_compressed(compressed.checked));
		reconnect.addEventListener("click",()=>mod.start(getWebSocket()));
		disconnect.addEventListener("click",mod.disconnect);
		refresh.addEventListener("click",mod.refresh);
		resume.addEventListener("click",mod.resume);
		pause.addEventListener("click",mod.pause);
		counter();
	}
});