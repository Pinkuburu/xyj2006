inherit SSERVER;
int cast(object me, object target)
{
        int invocation_time;
        object hufa;
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ�Τ�ӻ�����\n");
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
            return notify_fail("��սй�Τ�ӻ�������������з��ˣ�\n");
        if( (int)me->query("mana") < 150 )
                return notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query("sen") < 80 )
                return notify_fail("��ľ����޷����У�\n");
        message_vision("$N�૵����˼������\n", me);
        me->add("mana", -150);
        me->receive_damage("sen", 80);
        if( random(me->query("max_mana")) < 250 ) {
                message("vision", "����ʲôҲû�з�����\n",
environment(me));
                return 1;
}
        seteuid(getuid());
hufa = new("/obj/npc/hufa");
hufa->move(environment(me));
hufa->invocation(me);
hufa->set_temp("invoker",me);
        me->set("last_invocation",time());
        me->start_busy(2+random(2));
        return 8+random(5);
}